/* Forward declarations for core/login/phases/base_phase.c */

/* Alphabetized forward declarations (ctags) for core/login/phases/base_phase.c */
void begin_phase();
string cleaned(string value);
void clear_password_failures();
int contains_reserved(string value);
string display_name(string value);
void handle_input(string input);
int is_valid_name(string value);
int is_valid_password(string password);
string make_salt();
string normalized(string value);
void prompt_line(string message);
void prompt_secret(string message);
object query_session();
int register_password_failure();
int require_nonempty_input(string input);
void set_session(object new_session);
void write_line(string message);
