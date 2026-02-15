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

void session_write(string message) {
  if (!stringp(message))
    return;

  write(message);

  if (message == "" || message[<1] != '\n')
    write("\n");

  return;
}

void request_phase_input(int no_echo) {
  if (no_echo)
    input_to("receive_input", 1);
  else
    input_to("receive_input");

  return;
}

object query_current_phase() {
  if (!pointerp(phase_stack) || sizeof(phase_stack) == 0)
    return 0;

  return phase_stack[<1];
}

mapping query_session_data() {
  return session_data;
}

mixed query_session_value(string key) {
  if (!stringp(key) || key == "")
    return 0;

  return session_data[key];
}

void set_session_value(string key, mixed value) {
  if (!stringp(key) || key == "")
    return;

  session_data[key] = value;

  return;
}

void remove_session_value(string key) {
  if (!stringp(key) || key == "")
    return;

  map_delete(session_data, key);

  return;
}

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

void advance_phase(string path) {
  discard_current_phase();
  push_phase(path);

  return;
}

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

void disconnect_session(string message) {
  if (stringp(message) && message != "")
    session_write(message);

  destruct(this_object());

  return;
}
