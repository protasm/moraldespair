inherit "/core/object";

object session;

void set_session(object new_session) {
  session = new_session;

  return;
}

object query_session() {
  return session;
}

void begin_phase() {
  if (!objectp(session))
    return;

  session->request_phase_input(0);

  return;
}

void handle_input(string input) {
  if (!objectp(session))
    return;

  session->request_phase_input(0);

  return;
}

void write_line(string message) {
  if (!objectp(session))
    return;

  session->session_write(message);

  return;
}

void prompt_line(string message) {
  if (!objectp(session))
    return;

  write_line(message);
  session->request_phase_input(0);

  return;
}

void prompt_secret(string message) {
  if (!objectp(session))
    return;

  write_line(message);
  session->request_phase_input(1);

  return;
}

string cleaned(string value) {
  if (!stringp(value))
    return "";

  return trim(value);
}

string normalized(string value) {
  if (!stringp(value))
    return "";

  return lower_case(trim(value));
}

string display_name(string value) {
  value = normalized(value);

  if (value == "")
    return "";

  return capitalize(value);
}

int is_valid_name(string value) {
  string *matches;
  int length;

  if (!stringp(value))
    return 0;

  value = cleaned(value);
  length = strlen(value);

  if (length < 3 || length > 20)
    return 0;

  matches = regexp(({ value }), "^[A-Za-z]+$");

  if (!pointerp(matches) || sizeof(matches) == 0)
    return 0;

  return 1;
}

int is_valid_password(string password) {
  string *matches;
  int length;

  if (!stringp(password))
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

  lowered = normalized(value);
  terms = ({
    "account", "admin", "guest", "new", "create",
    "fuck", "shit", "cunt", "bitch", "asshole", "ass",
    "bastard", "whore"
  });

  for (i = 0; i < sizeof(terms); i++)
    if (strsrch(lowered, terms[i]) != -1)
      return 1;

  return 0;
}

string make_salt() {
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
