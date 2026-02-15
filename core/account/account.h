int handle_command(string verb, string arg);
string email();
int set_email(string new_email);
string password_hash();
int set_password_hash(string new_hash);
string *players();
int set_players(string *players);
int last_login();
int set_last_login(int last_login);
string normalize_key(string value);

/* Alphabetized forward declarations for core/account/account.c */

/* Alphabetized forward declarations (ctags) for core/account/account.c */
string account_file_path();
string email();
int handle_command(string verb, string arg);
int last_login();
mapping load_account_data();
string normalize_key(string value);
string password_hash();
string *players();
int save_account_data(mapping account);
int set_email(string new_email);
int set_last_login(int last_login);
int set_password_hash(string new_hash);
int set_players(string *players);
void set_username(string new_username);
string username();
