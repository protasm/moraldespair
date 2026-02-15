/*
 * Master Summary:
 * Purpose:
 *   Implements the object behavior defined in core/login/login-session-flow.c.
 * Approach:
 *   Uses explicit LPC methods with straightforward control flow so
 *   behavior stays predictable, debuggable, and easy to evolve.
 * Dependencies:
 *   - none
 */

/* Method Summary:
 * Purpose:
 *   Handles normalize_path for this object.
 * Parameters:
 *   - string path
 * Approach:
 *   Validates inputs and executes explicit local logic for normalize_path.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   string result from normalize_path.
 */
string normalize_path(string path) {
  if (!stringp(path))
    return "";

  path = trim(path);

  if (path == "")
    return "";

  if (path[0] != '/')
    path = "/" + path;

  if (sizeof(path) > 2 && path[<2..<1] == ".c")
    path = path[0..<3];

  return path;
}

/* Method Summary:
 * Purpose:
 *   Handles session_write for this object.
 * Parameters:
 *   - string message
 * Approach:
 *   Validates inputs and executes explicit local logic for session_write.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   void result from session_write.
 */
void session_write(string message) {
  if (!stringp(message))
    return;

  write(message);

  if (message == "" || message[<1] != '\n')
    write("\n");

  return;
}

/* Method Summary:
 * Purpose:
 *   Handles request_phase_input for this object.
 * Parameters:
 *   - int no_echo
 * Approach:
 *   Validates inputs and executes explicit local logic for request_phase_input.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   void result from request_phase_input.
 */
void request_phase_input(int no_echo) {
  write(PLAYER_PROMPT);

  if (no_echo)
    input_to("receive_input", 1);
  else
    input_to("receive_input");

  return;
}

/* Method Summary:
 * Purpose:
 *   Handles query_current_phase for this object.
 * Parameters:
 *   - none
 * Approach:
 *   Validates inputs and executes explicit local logic for query_current_phase.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   object result from query_current_phase.
 */
object query_current_phase() {
  if (!pointerp(phase_stack) || sizeof(phase_stack) == 0)
    return 0;

  return phase_stack[<1];
}

/* Method Summary:
 * Purpose:
 *   Handles query_session_data for this object.
 * Parameters:
 *   - none
 * Approach:
 *   Validates inputs and executes explicit local logic for query_session_data.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   mapping result from query_session_data.
 */
mapping query_session_data() {
  return session_data;
}

/* Method Summary:
 * Purpose:
 *   Handles query_session_value for this object.
 * Parameters:
 *   - string key
 * Approach:
 *   Validates inputs and executes explicit local logic for query_session_value.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   mixed result from query_session_value.
 */
mixed query_session_value(string key) {
  if (!stringp(key) || key == "")
    return 0;

  return session_data[key];
}

/* Method Summary:
 * Purpose:
 *   Handles set_session_value for this object.
 * Parameters:
 *   - string key, mixed value
 * Approach:
 *   Validates inputs and executes explicit local logic for set_session_value.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   void result from set_session_value.
 */
void set_session_value(string key, mixed value) {
  if (!stringp(key) || key == "")
    return;

  session_data[key] = value;

  return;
}

/* Method Summary:
 * Purpose:
 *   Handles remove_session_value for this object.
 * Parameters:
 *   - string key
 * Approach:
 *   Validates inputs and executes explicit local logic for remove_session_value.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   void result from remove_session_value.
 */
void remove_session_value(string key) {
  if (!stringp(key) || key == "")
    return;

  map_delete(session_data, key);

  return;
}

/* Method Summary:
 * Purpose:
 *   Handles begin_current_phase for this object.
 * Parameters:
 *   - none
 * Approach:
 *   Validates inputs and executes explicit local logic for begin_current_phase.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   void result from begin_current_phase.
 */
void begin_current_phase() {
  object phase;

  phase = query_current_phase();

  if (!objectp(phase)) {
    session_write("Session closed.");
    destruct(this_object());
    return;
  }

  if (!function_exists("begin_phase", phase)) {
    session_write("Login flow error.");
    destruct(this_object());
    return;
  }

  phase->begin_phase();

  return;
}

/* Method Summary:
 * Purpose:
 *   Handles push_phase for this object.
 * Parameters:
 *   - string path
 * Approach:
 *   Validates inputs and executes explicit local logic for push_phase.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   void result from push_phase.
 */
void push_phase(string path) {
  object phase;

  path = normalize_path(path);

  if (path == "") {
    session_write("Login flow error.");
    return;
  }

  phase = new(path);

  if (!objectp(phase)) {
    session_write("Failed to load login phase.");
    return;
  }

  if (!function_exists("set_session", phase)) {
    session_write("Invalid login phase.");
    destruct(phase);
    return;
  }

  phase->set_session(this_object());
  phase_stack += ({ phase });

  begin_current_phase();

  return;
}

/* Method Summary:
 * Purpose:
 *   Handles discard_current_phase for this object.
 * Parameters:
 *   - none
 * Approach:
 *   Validates inputs and executes explicit local logic for discard_current_phase.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   void result from discard_current_phase.
 */
void discard_current_phase() {
  object phase;

  phase = query_current_phase();

  if (!objectp(phase))
    return;

  if (sizeof(phase_stack) == 1)
    phase_stack = ({});
  else
    phase_stack = phase_stack[0..<2];

  destruct(phase);

  return;
}

/* Method Summary:
 * Purpose:
 *   Handles advance_phase for this object.
 * Parameters:
 *   - string path
 * Approach:
 *   Validates inputs and executes explicit local logic for advance_phase.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   void result from advance_phase.
 */
void advance_phase(string path) {
  discard_current_phase();
  push_phase(path);

  return;
}

/* Method Summary:
 * Purpose:
 *   Handles pop_phase for this object.
 * Parameters:
 *   - none
 * Approach:
 *   Validates inputs and executes explicit local logic for pop_phase.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   void result from pop_phase.
 */
void pop_phase() {
  discard_current_phase();

  if (sizeof(phase_stack) > 0)
    begin_current_phase();
  else {
    session_write("Session closed.");
    destruct(this_object());
  }

  return;
}

/* Method Summary:
 * Purpose:
 *   Handles receive_input for this object.
 * Parameters:
 *   - string input
 * Approach:
 *   Validates inputs and executes explicit local logic for receive_input.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   void result from receive_input.
 */
void receive_input(string input) {
  object phase;

  phase = query_current_phase();

  if (!objectp(phase)) {
    session_write("Session closed.");
    destruct(this_object());
    return;
  }

  if (!function_exists("handle_input", phase)) {
    session_write("Login flow error.");
    destruct(this_object());
    return;
  }

  phase->handle_input(input);

  return;
}

/* Method Summary:
 * Purpose:
 *   Handles disconnect_session for this object.
 * Parameters:
 *   - string message
 * Approach:
 *   Validates inputs and executes explicit local logic for disconnect_session.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   void result from disconnect_session.
 */
void disconnect_session(string message) {
  if (stringp(message) && message != "")
    session_write(message);

  destruct(this_object());

  return;
}
