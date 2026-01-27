#include "/daemon/account_d.h"

string account_root;

void create() {
  account_root = "/a";

  ensure_account_root();
}

string normalize_key(string value) {
  if (!stringp(value))
    return "";

  return lower_case(trim(value));
}

string account_dir(string username) {
  username = normalize_key(username);

  if (username == "")
    return "";

  return account_root + "/" + username;
}

string account_file(string username) {
  string dir;

  dir = account_dir(username);

  if (dir == "")
    return "";

  return dir + "/account.o";
}

string avatar_file(string username, string avatar_name) {
  string dir;
  string normalized;

  dir = account_dir(username);
  normalized = normalize_key(avatar_name);

  if (dir == "" || normalized == "")
    return "";

  return dir + "/" + normalized + ".o";
}

void ensure_account_root() {
  if (file_size(account_root) != -2)
    mkdir(account_root);
}

void ensure_account_dir(string username) {
  string dir;

  ensure_account_root();
  dir = account_dir(username);

  if (dir == "")
    return;

  if (file_size(dir) != -2)
    mkdir(dir);
}

mapping load_data(string path) {
  mapping data;
  string raw;

  if (path == "")
    return 0;

  if (file_size(path) <= 0)
    return 0;

  raw = read_file(path);

  if (!stringp(raw))
    return 0;

  data = restore_variable(raw);

  if (!mapp(data))
    return 0;

  return data;
}

int save_data(string path, mapping data) {
  string raw;

  if (path == "")
    return 0;

  if (!mapp(data))
    return 0;

  raw = save_variable(data);

  rm(path);

  return write_file(path, raw);
}

int account_exists(string username) {
  string path;

  username = normalize_key(username);

  if (username == "")
    return 0;

  path = account_file(username);

  if (path == "")
    return 0;

  return file_size(path) > 0;
}

string query_username_by_email(string email) {
  string *names;
  string dir;
  string path;
  mapping account;
  string normalized;
  int i;

  normalized = normalize_key(email);

  if (normalized == "")
    return "";

  ensure_account_root();
  names = get_dir(account_root + "/*");

  if (!pointerp(names))
    return "";

  for (i = 0; i < sizeof(names); i++) {
    dir = account_root + "/" + names[i];

    if (file_size(dir) != -2)
      continue;

    path = account_file(names[i]);
    account = load_data(path);

    if (!mapp(account))
      continue;

    if (account["email"] == normalized)
      return account["username"];
  }

  return "";
}

string query_password_hash(string username) {
  mapping account;

  username = normalize_key(username);
  account = load_data(account_file(username));

  if (!mapp(account))
    return "";

  return account["password_hash"];
}

string query_display_name(string username) {
  mapping account;

  username = normalize_key(username);
  account = load_data(account_file(username));

  if (!mapp(account))
    return "";

  return account["display_name"];
}

string *query_avatars(string username) {
  mapping account;
  string *avatars;

  username = normalize_key(username);
  account = load_data(account_file(username));

  if (!mapp(account))
    return ({});

  avatars = account["avatars"];

  if (!pointerp(avatars))
    return ({});

  return avatars;
}

int avatar_exists(string username, string avatar_name) {
  string *avatars;
  string normalized;
  int i;

  avatars = query_avatars(username);
  normalized = normalize_key(avatar_name);

  for (i = 0; i < sizeof(avatars); i++) {
    if (normalize_key(avatars[i]) == normalized)
      return 1;
  }

  return 0;
}

int create_account(string username, string display_name, string email,
                   string password_hash) {
  mapping account;
  int saved;

  username = normalize_key(username);
  email = normalize_key(email);

  if (username == "" || email == "")
    return 0;

  if (account_exists(username))
    return 0;

  account = ([]);
  account["username"] = username;
  account["display_name"] = display_name;
  account["email"] = email;
  account["password_hash"] = password_hash;
  account["avatars"] = ({});
  account["last_login"] = 0;

  ensure_account_dir(username);
  saved = save_data(account_file(username), account);

  return saved;
}

int add_avatar(string username, string avatar_name) {
  mapping account;
  string *avatars;
  mapping avatar;
  string path;
  int saved;

  if (!account_exists(username))
    return 0;

  if (avatar_exists(username, avatar_name))
    return 0;

  account = load_data(account_file(username));

  if (!mapp(account))
    return 0;

  avatars = account["avatars"];

  if (!pointerp(avatars))
    avatars = ({});

  avatars += ({ avatar_name });
  account["avatars"] = avatars;
  saved = save_data(account_file(username), account);

  if (!saved)
    return 0;

  avatar = ([]);
  avatar["display_name"] = avatar_name;
  avatar["brief"] = 0;
  avatar["last_played"] = 0;

  path = avatar_file(username, avatar_name);

  if (path == "")
    return 0;

  ensure_account_dir(username);

  return save_data(path, avatar);
}

void record_login(string username) {
  mapping account;

  if (!account_exists(username))
    return;

  account = load_data(account_file(username));

  if (!mapp(account))
    return;

  account["last_login"] = time();

  save_data(account_file(username), account);
}

void record_avatar_login(string username, string avatar_name) {
  mapping avatar;
  string path;

  if (!account_exists(username))
    return;

  path = avatar_file(username, avatar_name);
  avatar = load_data(path);

  if (!mapp(avatar))
    return;

  avatar["last_played"] = time();

  save_data(path, avatar);
}
