/* Companion header file. */

/* Alphabetized forward declarations for core/mfun/mfun.c */
object avatar_account(object avatar);
object avatar_controller(object avatar);
int avatar_experience(object avatar, string text);
string avatar_id(object avatar);
string avatar_name(object avatar);
object *connected_avatars();
object current_avatar();
object current_session();
string *directions();
int is_avatar(object obj);
int is_connected_avatar(object obj);
int is_direction(string str);
int is_member(mixed container, mixed item);
int member(mixed container, mixed item);
object resolve_environment_target(object actor, string target);
string session_account_name(object session);
int session_authenticated(object session);
string session_selected_avatar(object session);
string wrap_text(string text);

/* Alphabetized forward declarations (ctags) for core/mfun/mfun.c */
object avatar_account(object avatar);
object avatar_controller(object avatar);
int avatar_experience(object avatar, string text);
string avatar_id(object avatar);
string avatar_name(object avatar);
object *connected_avatars();
object current_avatar();
object current_session();
string *directions();
int is_avatar(object obj);
int is_connected_avatar(object obj);
int is_direction(string str);
int is_member(mixed container, mixed item);
int member(mixed container, mixed item);
object resolve_environment_target(object actor, string target);
string session_account_name(object session);
int session_authenticated(object session);
string session_selected_avatar(object session);
string wrap_text(string text);
