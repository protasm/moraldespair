#include <globals.h>

private string pending_username;
private string pending_display_name;
private string pending_email;
private string pending_password;
private string pending_existing_username;

static void prompt_username();
static void prompt_email();
static void prompt_new_username();
static void prompt_existing_password();
static void prompt_new_password();
static void prompt_avatar();
static void prompt_avatar_choice(string *avatars);
static void prompt_avatar_selection();
static void start_player_session(string avatar_name);
static void clear_pending();
static string normalize_value(string value);
static string format_display_name(string value);
static int is_valid_email(string email);
static int is_valid_username(string name);
static int is_valid_password(string password);
static int contains_profanity(string value);
static string make_salt();

void logon() {
  clear_pending();

  write("Welcome!  What is your username?\n");
  prompt_username();
}

static void clear_pending() {
  pending_username = "";
  pending_display_name = "";
  pending_email = "";
  pending_password = "";
  pending_existing_username = "";
}

static string normalize_value(string value) {
  if (!stringp(value))
    return "";

  return lower_case(trim(value));
}

static string format_display_name(string value) {
  value = normalize_value(value);

  if (value == "")
    return "";

  return capitalize(value);
}

static void prompt_username() {
  write("> ");
  input_to("handle_username");
}

static void prompt_email() {
  write("What is your email address?\n");
  write("> ");
  input_to("handle_email");
}

static void prompt_new_username() {
  write("Got it.  What would you like your username to be?\n");
  write("> ");
  input_to("handle_new_username");
}

static void prompt_existing_password() {
  write("Please enter your password:\n");
  write("> ");
  input_to("handle_password_existing");
}

static void prompt_new_password() {
  write("> ");
  input_to("handle_password");
}

static void prompt_avatar() {
  write("Finally, let's add an avatar (i.e., a character) to your account.\n");
  write("What would you like to name your first avatar?\n");
  write("> ");
  input_to("handle_new_avatar");
}

static void prompt_avatar_choice(string *avatars) {
  int i;

  write("Which avatar would you like to use?\n");

  for (i = 0; i < sizeof(avatars); i++)
    write("  - " + avatars[i] + "\n");

  write("> ");
  input_to("handle_avatar_choice");
}

static int is_valid_email(string email) {
  string *matches;

  if (email == "")
    return 0;

  matches = regexp(({ email }), "^[^@ ]+@[^@ ]+\\.[^@ ]+$");

  if (!pointerp(matches) || sizeof(matches) == 0)
    return 0;

  return 1;
}

static int is_valid_username(string name) {
  string *matches;
  int length;

  if (name == "")
    return 0;

  matches = regexp(({ name }), "^[A-Za-z]+$");
  length = strlen(name);

  if (!pointerp(matches) || sizeof(matches) == 0)
    return 0;

  if (length < 3 || length > 20)
    return 0;

  return 1;
}

static int is_valid_password(string password) {
  string *matches;
  int length;

  if (password == "")
    return 0;

  length = strlen(password);

  if (length < 6 || length > 20)
    return 0;

  matches = regexp(({ password }), "[0-9]");
  if (!pointerp(matches) || sizeof(matches) == 0)
    return 0;

  matches = regexp(({ password }), "[A-Z]");
  if (!pointerp(matches) || sizeof(matches) == 0)
    return 0;

  matches = regexp(({ password }), "[a-z]");
  if (!pointerp(matches) || sizeof(matches) == 0)
    return 0;

  matches = regexp(({ password }), "[!@#$%^&*]");
  if (!pointerp(matches) || sizeof(matches) == 0)
    return 0;

  return 1;
}

static int contains_profanity(string value) {
  string lowered;
  string *terms;
  int i;

  lowered = lower_case(value);
  terms = ({ "fuck", "shit", "cunt", "bitch", "asshole" });

  for (i = 0; i < sizeof(terms); i++) {
    if (strsrch(lowered, terms[i]) != -1)
      return 1;
  }

  return 0;
}

static string make_salt() {
  string chars;
  string salt;
  int i;
  int j;

  chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789./";
  i = random(strlen(chars));
  j = random(strlen(chars));
  salt = chars[i..i] + chars[j..j];

  return salt;
}

void handle_username(string input) {
  string username;
  string raw;

  if (!stringp(input))
    input = "";

  raw = trim(input);
  username = normalize_value(raw);

  if (username == "") {
    prompt_username();
    return;
  }

  if (username == "new") {
    write("New account - great!\n");
    prompt_email();
    return;
  }

  if (ACCOUNT_D->account_exists(username)) {
    pending_username = username;
    pending_display_name = ACCOUNT_D->query_display_name(username);
    prompt_existing_password();
    return;
  }

  write("Sorry, I don't recognize \"" + raw + "\".  Please try again.\n");
  write("(Or, enter \"new\" to create a new account.)\n");
  prompt_username();
}

void handle_email(string input) {
  string email;
  string existing;
  string raw;

  if (!stringp(input))
    input = "";

  raw = trim(input);
  email = normalize_value(raw);

  if (!is_valid_email(email)) {
    write("Sorry, that's not a valid email address.  Please try again.\n");
    prompt_email();
    return;
  }

  existing = ACCOUNT_D->query_username_by_email(email);

  if (existing != "") {
    pending_existing_username = existing;
    pending_email = email;
    write("That email address is already associated with an account.\n");
    write("Would you like to log in with that account? [y/n]\n");
    write("> ");
    input_to("handle_existing_email");
    return;
  }

  pending_email = email;
  prompt_new_username();
}

void handle_existing_email(string input) {
  string response;

  if (!stringp(input))
    input = "";

  response = normalize_value(input);

  if (response == "y" || response == "yes") {
    pending_username = pending_existing_username;
    pending_display_name = ACCOUNT_D->query_display_name(pending_username);
    prompt_existing_password();
    return;
  }

  if (response == "n" || response == "no") {
    prompt_email();
    return;
  }

  write("Please type \"[y]es\" or \"[n]o\".\n");
  write("> ");
  input_to("handle_existing_email");
}

void handle_new_username(string input) {
  string raw;
  string normalized;

  if (!stringp(input))
    input = "";

  raw = trim(input);

  if (raw == "") {
    prompt_new_username();
    return;
  }

  if (contains_profanity(raw)) {
    write("Sorry, profanity is not allowed.  Try again?\n");
    prompt_new_username();
    return;
  }

  if (!is_valid_username(raw)) {
    write("Just one word, please, with no punctuation or special characters.\n");
    prompt_new_username();
    return;
  }

  normalized = normalize_value(raw);

  if (ACCOUNT_D->account_exists(normalized)) {
    write("That username is already taken.  Please try again.\n");
    prompt_new_username();
    return;
  }

  pending_username = normalized;
  pending_display_name = format_display_name(raw);

  write("Okay, \"" + pending_display_name + "\" it is!  Now, you need a ");
  write("password.\n");
  write("A password can be 6-20 characters long, with at least\n");
  write("one number, one upper-case letter, one lower-case letter,\n");
  write("and one special character (!@#$%^&*).\n");
  prompt_new_password();
}

void handle_password(string input) {
  if (!stringp(input))
    input = "";

  if (!is_valid_password(input)) {
    write("Hmm, that won't work.  Please try again.\n");
    write("A password can be 6-20 characters long, with at least\n");
    write("one number, one upper-case letter, one lower-case letter,\n");
    write("and one special character (!@#$%^&*).\n");
    prompt_new_password();
    return;
  }

  pending_password = input;

  write("That works!  Please type it again, to confirm:\n");
  write("> ");
  input_to("handle_password_confirm");
}

void handle_password_confirm(string input) {
  string password_hash;

  if (!stringp(input))
    input = "";

  if (input != pending_password) {
    write("Oh, man.  They didn't match.  Try again?\n");
    write("A password can be 6-20 characters long, with at least\n");
    write("one number, one upper-case letter, one lower-case letter,\n");
    write("and one special character (!@#$%^&*).\n");
    prompt_new_password();
    return;
  }

  password_hash = crypt(pending_password, make_salt());

  if (!ACCOUNT_D->create_account(pending_username, pending_display_name,
                                pending_email, password_hash)) {
    write("Something went wrong while creating your account.\n");
    prompt_username();
    return;
  }

  write("Confirmed!\n");
  write("Finally, let's add an avatar (i.e., a character) to your account.\n");
  write("What would you like to name your first avatar?\n");
  write("> ");
  input_to("handle_new_avatar");
}

void handle_new_avatar(string input) {
  string raw;
  string display;

  if (!stringp(input))
    input = "";

  raw = trim(input);

  if (raw == "") {
    prompt_avatar();
    return;
  }

  if (contains_profanity(raw)) {
    write("Sorry, profanity is not allowed.  Try again?\n");
    prompt_avatar();
    return;
  }

  if (!is_valid_username(raw)) {
    write("Just one word, please, with no punctuation or special characters.\n");
    prompt_avatar();
    return;
  }

  display = format_display_name(raw);

  if (ACCOUNT_D->avatar_exists(pending_username, display)) {
    write("That avatar already exists on your account.  Try again?\n");
    prompt_avatar();
    return;
  }

  if (!ACCOUNT_D->add_avatar(pending_username, display)) {
    write("Something went wrong while creating your avatar.\n");
    prompt_avatar();
    return;
  }

  write("Perfect - \"" + display + "\" has been added to your account.\n");
  write("And now... let's play!\n");
  write("Connecting as " + display + "....\n");

  start_player_session(display);
}

void handle_password_existing(string input) {
  string password_hash;
  string attempt_hash;

  if (!stringp(input))
    input = "";

  password_hash = ACCOUNT_D->query_password_hash(pending_username);

  if (password_hash == "") {
    write("Password incorrect.  Try again.\n");
    prompt_existing_password();
    return;
  }

  attempt_hash = crypt(input, password_hash);

  if (attempt_hash != password_hash) {
    write("Password incorrect.  Try again.\n");
    prompt_existing_password();
    return;
  }

  prompt_avatar_selection();
}

void handle_avatar_choice(string input) {
  string choice;
  string *avatars;
  int i;

  if (!stringp(input))
    input = "";

  choice = normalize_value(input);
  avatars = ACCOUNT_D->query_avatars(pending_username);

  for (i = 0; i < sizeof(avatars); i++) {
    if (normalize_value(avatars[i]) == choice) {
      write("Connecting as " + avatars[i] + "....\n");
      start_player_session(avatars[i]);
      return;
    }
  }

  write("Sorry, that avatar isn't on your account.  Try again.\n");
  prompt_avatar_choice(avatars);
}

static void prompt_avatar_selection() {
  string *avatars;

  avatars = ACCOUNT_D->query_avatars(pending_username);

  if (sizeof(avatars) == 0) {
    prompt_avatar();
    return;
  }

  if (sizeof(avatars) == 1) {
    write("Connecting as " + avatars[0] + "....\n");
    start_player_session(avatars[0]);
    return;
  }

  prompt_avatar_choice(avatars);
}

static void start_player_session(string avatar_name) {
  object player;

  player = new(PLAYER_OB);
  player->set_name(avatar_name);
  player->set_account(pending_username);

  exec(player, this_object());

  player->move(START_ROOM);
  player->show_location();
  player->start_session();

  destruct(this_object());
}
