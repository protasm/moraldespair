string normalize_key(string value);
string account_dir(string username);
string account_file(string username);
string player_file(string username, string player_name);
void ensure_account_root();
void ensure_account_dir(string username);
mapping load_data(string path);
int save_data(string path, mapping data);
string last_played_player(string username);
int max_players_per_account();
int player_slots_remaining(string username);

/* Alphabetized forward declarations for core/daemon/account_d.c */

/* Alphabetized forward declarations (ctags) for core/daemon/account_d.c */
string account_dir(string username);
int account_exists(string username);
string account_file(string username);
int add_player(string username, string player_name);
void create();
int create_account(string username, string display_name, string email,;
string display_name(string username);
void ensure_account_dir(string username);
void ensure_account_root();
string last_played_player(string username);
mapping load_data(string path);
int max_players_per_account();
string normalize_key(string value);
string password_hash(string username);
int player_exists(string username, string player_name);
string player_file(string username, string player_name);
int player_slots_remaining(string username);
string *players(string username);
void record_login(string username);
void record_player_login(string username, string player_name);
int save_data(string path, mapping data);
string username_by_email(string email);
