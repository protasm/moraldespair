#include <globals.h>

#include "login.h"

private string pending_username;
private string pending_display_name;
private string pending_email;
private string pending_password;
private string pending_existing_username;

void logon() {
  clear_pending();

  cat(WELCOME_FILE, 1, 1);

  write("Welcome!  What is your username?\n");

  prompt_username();
}

void clear_pending() {
  pending_display_name = "";
  pending_existing_username = "";
}

string normalize_value(string value) {
  if (!stringp(value))
    return "";

  return lower_case(trim(value));
}

string format_display_name(string value) {
  value = normalize_value(value);

  if (value == "")
    return "";

  return capitalize(value);
}

void prompt_username() {
  write_prompt("(Type \"create\" to create a new account.)");

  input_to("handle_username");
}

void prompt_email() {
  pending_email = "";

  write_prompt("What is your email address?");

  input_to("handle_email");
}

void prompt_new_username() {
  pending_username = "";

  write_prompt("Got it.  What would you like your username to be?");

  input_to("handle_new_username");
}

void prompt_existing_password() {
  write_prompt("Please enter your password:");

  input_to("handle_password_existing", 1);
}

void write_password_advice() {
  write("A password should be 6-20 characters long, with at least\n");
  write("one number, one upper-case letter, one lower-case letter,\n");
  write("and one special character (!@#$%^&*).\n");
}

void prompt_new_password() {
  pending_password = "";

  write_password_advice();

  write_prompt("");

  input_to("handle_password", 1);
}

void prompt_player() {
  write("Finally, let's add a player name to your account.\n");
  write_prompt("What would you like to name your first player?");

  input_to("handle_new_player");
}

void prompt_player_choice(string *players) {
  int i;

  write("Which player would you like to use?\n");

  for (i = 0; i < sizeof(players); i++)
    write("  - " + players[i] + "\n");

  write_prompt("");

  input_to("handle_player_choice");
}

int is_valid_email(string email) {
  string *matches;

  if (email == "")
    return 0;

  matches = regexp(({ email }), "^[^@ ]+@[^@ ]+\\.[^@ ]+$");

  if (!pointerp(matches) || sizeof(matches) == 0)
    return 0;

  return 1;
}

int is_valid_username(string name) {
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

int is_valid_password(string password) {
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

int contains_reserved(string value) {
  string lowered;
  string *terms;
  int i;

  lowered = lower_case(value);
  terms = ({
    "account", "email", "user", "guest", "new", "create",
    "fuck", "shit", "cunt", "bitch", "asshole", "ass",
    "bastard", "whore",
   });

  for (i = 0; i < sizeof(terms); i++)
    if (strsrch(lowered, terms[i]) != -1)
      return 1;

  return 0;
}

string make_salt() {
  string chars, salt;
  int i, j;

  chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789./";
  i = random(strlen(chars));
  j = random(strlen(chars));
  salt = chars[i..i] + chars[j..j];

  return salt;
}

void handle_username(string input) {
  string raw, username;

  if (!stringp(input))
    input = "";

  raw = trim(input);
  username = normalize_value(raw);

  if (username == "") {
    prompt_username();

    return;
  }

  if (username == "create") {
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

  prompt_username();
}

void handle_email(string input) {
  string raw, email;

  if (!stringp(input))
    input = "";

  raw = trim(input);
  email = normalize_value(raw);

  if (!is_valid_email(email)) {
    write("Sorry, that's not a valid email address.  Please try again.\n");

    prompt_email();

    return;
  }

  /* TODO
  string existing;

  existing = ACCOUNT_D->query_username_by_email(email);

  if (existing != "") {
    pending_existing_username = existing;
    pending_email = email;

    write("That email address is already associated with an account.\n");
    write_prompt("Would you like to log in with that account? [y/n]");

    input_to("handle_existing_email");

    return;
  }
  */

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

  write_prompt("Please type \"[y]es\" or \"[n]o\".");

  input_to("handle_existing_email");
}

void handle_new_username(string input) {
  string raw, normalized;

  if (!stringp(input))
    input = "";

  raw = trim(input);

  if (raw == "") {
    prompt_new_username();

    return;
  }

  if (contains_reserved(raw)) {
    write("Sorry, that word is not allowed.  Try again?\n");

    prompt_new_username();

    return;
  }

  if (!is_valid_username(raw)) {
    write("Just one word, please, with no punctuation or special characters.\n");

    prompt_new_username();

    return;
  }

  normalized = normalize_value(raw);

  /* TODO
  if (ACCOUNT_D->account_exists(normalized)) {
    write("That username is already taken.  Please try again.\n");

    prompt_new_username();

    return;
  }
  */

  pending_username = normalized;
  pending_display_name = format_display_name(raw);

  write("Okay, \"" + pending_display_name + "\" it is!  Now, you need a ");
  write("password.\n");

  prompt_new_password();
}

void handle_password(string input) {
  input = stringp(input) ? input : "";

  /* Confirmation phase */
  if (pending_password != "") {
    if (input != pending_password) {
      write("Oh, man. They didn't match. Start over?\n");

      prompt_new_password();

      return;
    }

    write("\nNice, they match! Creating account....\n");

    create_account();

    return;
  }

  /* Initial password selection */
  if (!is_valid_password(input)) {
    write("Hmm, that password won't work. Please try again.\n");

    prompt_new_password();

    return;
  }

  pending_password = input;

  write("\nThat works! Please type it again, to confirm:\n> ");

  input_to("handle_password", 1);
}

void create_account() {
  string password_hash;

  password_hash = crypt(pending_password, make_salt());

  if (!ACCOUNT_D->create_account(
    pending_username, pending_display_name,
    pending_email, password_hash)
  ) {
    write("Something went wrong while creating your account.\n");

    prompt_username();

    return;
  }

  ACCOUNT_D->record_login(pending_username);

  write("Account created - we're in business!\n");

  prompt_player();
}

void handle_new_player(string input) {
  string raw, display;

  if (!stringp(input))
    input = "";

  raw = trim(input);

  if (raw == "") {
    prompt_player();

    return;
  }

  if (contains_reserved(raw)) {
    write("Sorry, that word is not allowed.  Try again?\n");

    prompt_player();

    return;
  }

  if (!is_valid_username(raw)) {
    write("Just one word, please, with no punctuation or special characters.\n");

    prompt_player();

    return;
  }

  display = format_display_name(raw);

  /* TODO
  if (ACCOUNT_D->player_exists(pending_username, display)) {
    write("That player already exists on your account.  Try again?\n");

    prompt_player();

    return;
  }
  */

  if (!ACCOUNT_D->add_player(pending_username, display)) {
    write("Something went wrong while creating your player.\n");

    prompt_player();

    return;
  }

  write("Perfect - \"" + display + "\" has been added to your account.\n");
  write("And now... let's play!\n\n");
  write("Connecting as " + display + "....\n");

  start_session(display);
}

void handle_password_existing(string input) {
  string password_hash, attempt_hash;

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

  ACCOUNT_D->record_login(pending_username);

  prompt_player_selection();
}

void handle_player_choice(string input) {
  string choice;
  string *players;
  int i;

  if (!stringp(input))
    input = "";

  choice = normalize_value(input);
  players = ACCOUNT_D->query_players(pending_username);

  for (i = 0; i < sizeof(players); i++)
    if (normalize_value(players[i]) == choice) {
      write("Connecting as " + players[i] + "....\n");

      start_session(players[i]);

      return;
    }

  write("Sorry, that player isn't on your account.  Try again.\n");

  prompt_player_choice(players);
}

void prompt_player_selection() {
  string *players;

  players = ACCOUNT_D->query_players(pending_username);

  if (sizeof(players) == 0) {
    prompt_player();

    return;
  }

  if (sizeof(players) == 1) {
    write("Connecting as " + players[0] + "....\n");

    start_session(players[0]);

    return;
  }

  prompt_player_choice(players);
}

void start_session(string player_name) {
  object account, player;
  int brief;

  account = new(ACCOUNT_OB);
  player = new(PLAYER_OB);

  account->set_username(pending_username);

  player->set_account(account);
  player->set_name(player_name);

  brief = player->query_brief();
  player->set_brief(brief);

  ACCOUNT_D->record_player_login(pending_username, player_name);

  exec(player, this_object());

  cat(MOTD_FILE, 1, 1);

  move_object(START_ROOM);
  player->show_location();

  destruct(this_object());
}

void write_prompt(string question) {
  if (question != "")
    write(question + "\n");

  write(PLAYER_PROMPT);
}
