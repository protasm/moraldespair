/* Forward declarations for core/login/login-session-flow.c */

/* Alphabetized forward declarations (ctags) for core/login/login-session-flow.c */
void advance_phase(string path);
void begin_current_phase();
void discard_current_phase();
void disconnect_session(string message);
string normalize_path(string path);
void pop_phase();
void push_phase(string path);
object query_current_phase();
mapping query_session_data();
mixed query_session_value(string key);
void receive_input(string input);
void remove_session_value(string key);
void request_phase_input(int no_echo);
void session_write(string message);
void set_session_value(string key, mixed value);
