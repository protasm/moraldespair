static mapping accounts;
static string save_file;

static void ensure_save_dir();
static string normalize_key(string value);

void create() {
  save_file = "/data/account/accounts";

  ensure_save_dir();
  restore_object(save_file);

  if (!mapp(accounts))
    accounts = ([]);
}

static void ensure_save_dir() {
  if (file_size("/data/account") != -2)
    mkdir("/data/account");
}

static void save_accounts() {
  ensure_save_dir();
  save_object(save_file);
}

static string normalize_key(string value) {
  if (!stringp(value))
    return "";

  return lower_case(trim(value));
}

int account_exists(string username) {
  username = normalize_key(username);

  if (username == "")
    return 0;

  if (!mapp(accounts[username]))
    return 0;

  return 1;
}

string query_username_by_email(string email) {
  string *names;
  string normalized;
  int i;

  normalized = normalize_key(email);

  if (normalized == "")
    return "";

  names = keys(accounts);

  for (i = 0; i < sizeof(names); i++) {
    if (accounts[names[i]]["email"] == normalized)
      return names[i];
  }

  return "";
}

string query_password_hash(string username) {
  mapping account;

  username = normalize_key(username);
  account = accounts[username];

  if (!mapp(account))
    return "";

  return account["password_hash"];
}

string query_display_name(string username) {
  mapping account;

  username = normalize_key(username);
  account = accounts[username];

  if (!mapp(account))
    return "";

  return account["display_name"];
}

string *query_avatars(string username) {
  mapping account;
  string *avatars;

  username = normalize_key(username);
  account = accounts[username];

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

  accounts[username] = account;

  save_accounts();

  return 1;
}

int add_avatar(string username, string avatar_name) {
  mapping account;
  string *avatars;

  if (!account_exists(username))
    return 0;

  if (avatar_exists(username, avatar_name))
    return 0;

  account = accounts[normalize_key(username)];
  avatars = account["avatars"];

  if (!pointerp(avatars))
    avatars = ({});

  avatars += ({ avatar_name });
  account["avatars"] = avatars;
  accounts[normalize_key(username)] = account;

  save_accounts();

  return 1;
}
