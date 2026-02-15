/*
 * Master Summary:
 * Purpose:
 *   Implements the object behavior defined in core/login/phases/base_phase.c.
 * Approach:
 *   Uses explicit LPC methods with straightforward control flow so
 *   behavior stays predictable, debuggable, and easy to evolve.
 * Dependencies:
 *   - inherit "/core/object/object";
 */

inherit "/core/object/object";

object session;

/* Method Summary:
 * Purpose:
 *   Handles set_session for this object.
 * Parameters:
 *   - object new_session
 * Approach:
 *   Validates inputs and executes explicit local logic for set_session.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   void result from set_session.
 */
void set_session(object new_session) {
  session = new_session;

  return;
}

/* Method Summary:
 * Purpose:
 *   Handles query_session for this object.
 * Parameters:
 *   - none
 * Approach:
 *   Validates inputs and executes explicit local logic for query_session.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   object result from query_session.
 */
object query_session() {
  return session;
}

/* Method Summary:
 * Purpose:
 *   Handles begin_phase for this object.
 * Parameters:
 *   - none
 * Approach:
 *   Validates inputs and executes explicit local logic for begin_phase.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   void result from begin_phase.
 */
void begin_phase() {
  if (!objectp(session))
    return;

  session->request_phase_input(0);

  return;
}

/* Method Summary:
 * Purpose:
 *   Handles handle_input for this object.
 * Parameters:
 *   - string input
 * Approach:
 *   Validates inputs and executes explicit local logic for handle_input.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   void result from handle_input.
 */
void handle_input(string input) {
  if (!objectp(session))
    return;

  session->request_phase_input(0);

  return;
}

/* Method Summary:
 * Purpose:
 *   Handles write_line for this object.
 * Parameters:
 *   - string message
 * Approach:
 *   Validates inputs and executes explicit local logic for write_line.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   void result from write_line.
 */
void write_line(string message) {
  if (!objectp(session))
    return;

  session->session_write(message);

  return;
}

/* Method Summary:
 * Purpose:
 *   Handles prompt_line for this object.
 * Parameters:
 *   - string message
 * Approach:
 *   Validates inputs and executes explicit local logic for prompt_line.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   void result from prompt_line.
 */
void prompt_line(string message) {
  if (!objectp(session))
    return;

  write_line(message);
  session->request_phase_input(0);

  return;
}

/* Method Summary:
 * Purpose:
 *   Handles prompt_secret for this object.
 * Parameters:
 *   - string message
 * Approach:
 *   Validates inputs and executes explicit local logic for prompt_secret.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   void result from prompt_secret.
 */
void prompt_secret(string message) {
  if (!objectp(session))
    return;

  write_line(message);
  session->request_phase_input(1);

  return;
}

/* Method Summary:
 * Purpose:
 *   Handles cleaned for this object.
 * Parameters:
 *   - string value
 * Approach:
 *   Validates inputs and executes explicit local logic for cleaned.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   string result from cleaned.
 */
string cleaned(string value) {
  if (!stringp(value))
    return "";

  return trim(value);
}

/* Method Summary:
 * Purpose:
 *   Handles normalized for this object.
 * Parameters:
 *   - string value
 * Approach:
 *   Validates inputs and executes explicit local logic for normalized.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   string result from normalized.
 */
string normalized(string value) {
  if (!stringp(value))
    return "";

  return lower_case(trim(value));
}

/* Method Summary:
 * Purpose:
 *   Handles display_name for this object.
 * Parameters:
 *   - string value
 * Approach:
 *   Validates inputs and executes explicit local logic for display_name.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   string result from display_name.
 */
string display_name(string value) {
  value = normalized(value);

  if (value == "")
    return "";

  return capitalize(value);
}

/* Method Summary:
 * Purpose:
 *   Handles is_valid_name for this object.
 * Parameters:
 *   - string value
 * Approach:
 *   Validates inputs and executes explicit local logic for is_valid_name.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   int result from is_valid_name.
 */
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

/* Method Summary:
 * Purpose:
 *   Handles is_valid_password for this object.
 * Parameters:
 *   - string password
 * Approach:
 *   Validates inputs and executes explicit local logic for is_valid_password.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   int result from is_valid_password.
 */
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

/* Method Summary:
 * Purpose:
 *   Handles contains_reserved for this object.
 * Parameters:
 *   - string value
 * Approach:
 *   Validates inputs and executes explicit local logic for contains_reserved.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   int result from contains_reserved.
 */
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

/* Method Summary:
 * Purpose:
 *   Handles make_salt for this object.
 * Parameters:
 *   - none
 * Approach:
 *   Validates inputs and executes explicit local logic for make_salt.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   string result from make_salt.
 */
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

/* Method Summary:
 * Purpose:
 *   Handles require_nonempty_input for this object.
 * Parameters:
 *   - string input
 * Approach:
 *   Validates inputs and executes explicit local logic for require_nonempty_input.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   int result from require_nonempty_input.
 */
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

/* Method Summary:
 * Purpose:
 *   Handles register_password_failure for this object.
 * Parameters:
 *   - none
 * Approach:
 *   Validates inputs and executes explicit local logic for register_password_failure.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   int result from register_password_failure.
 */
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

/* Method Summary:
 * Purpose:
 *   Handles clear_password_failures for this object.
 * Parameters:
 *   - none
 * Approach:
 *   Validates inputs and executes explicit local logic for clear_password_failures.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   void result from clear_password_failures.
 */
void clear_password_failures() {
  object current_session;

  current_session = query_session();

  if (!objectp(current_session))
    return;

  current_session->set_session_value("password_failure_count", 0);

  return;
}
