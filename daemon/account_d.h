string normalize_key(string value);
string account_dir(string username);
string account_file(string username);
string avatar_file(string username, string avatar_name);
void ensure_account_root();
void ensure_account_dir(string username);
mapping load_data(string path);
int save_data(string path, mapping data);

