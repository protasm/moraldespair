inherit "/core/object/object";

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

int require_nonempty_input(string input) {
  object current_session;
  string value;
  int empty_attempts;

  current_session = query_session();

  if (!objectp(current_session))
    return 1;

  value = cleaned(input);

  if (value != "") {
    current_session->set_session_value("required_empty_input_count", 0);
    return 0;
  }

  empty_attempts = current_session->query_session_value("required_empty_input_count");

  if (!intp(empty_attempts))
    empty_attempts = 0;

  empty_attempts += 1;
  current_session->set_session_value("required_empty_input_count", empty_attempts);

  if (empty_attempts >= 3) {
    current_session->disconnect_session(
      "No input was received after three attempts.\n"
      "Disconnecting for now. Please reconnect when ready."
    );
    return 1;
  }

  begin_phase();

  return 1;
}

int register_password_failure() {
  object current_session;
  int password_failures;

  current_session = query_session();

  if (!objectp(current_session))
    return 1;

  password_failures = current_session->query_session_value("password_failure_count");

  if (!intp(password_failures))
    password_failures = 0;

  password_failures += 1;
  current_session->set_session_value("password_failure_count", password_failures);

  if (password_failures >= 3) {
    current_session->disconnect_session(
      "Too many invalid password attempts.\n"
      "Disconnecting for now. Please reconnect when ready."
    );
    return 1;
  }

  return 0;
}

void clear_password_failures() {
  object current_session;

  current_session = query_session();

  if (!objectp(current_session))
    return;

  current_session->set_session_value("password_failure_count", 0);

  return;
}
