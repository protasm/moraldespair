#include "/daemon/account_d.h"
#include <globals.h>

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

string player_file(string username, string player_name) {
  string dir;
  string normalized;

  dir = account_dir(username);
  normalized = normalize_key(player_name);

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

string *query_players(string username) {
  mapping account;
  string *players;

  username = normalize_key(username);
  account = load_data(account_file(username));

  if (!mapp(account))
    return ({});

  players = account["players"];

  if (!pointerp(players)) {
    players = account["avatars"];

    if (!pointerp(players))
      return ({});
  }

  return players;
}

int player_exists(string username, string player_name) {
  string *players;
  string normalized;
  int i;

  players = query_players(username);
  normalized = normalize_key(player_name);

  for (i = 0; i < sizeof(players); i++) {
    if (normalize_key(players[i]) == normalized)
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
  account["players"] = ({});
  account["avatars"] = ({});
  account["last_login"] = 0;

  ensure_account_dir(username);
  saved = save_data(account_file(username), account);

  return saved;
}

int add_player(string username, string player_name) {
  mapping account;
  string *players;
  mapping player;
  string path;
  string default_chapter;
  int saved;

  if (!account_exists(username))
    return 0;

  if (player_exists(username, player_name))
    return 0;

  account = load_data(account_file(username));

  if (!mapp(account))
    return 0;

  players = account["players"];

  if (!pointerp(players)) {
    players = account["avatars"];

    if (!pointerp(players))
      players = ({});
  }

  players += ({ player_name });
  account["players"] = players;
  account["avatars"] = players;
  saved = save_data(account_file(username), account);

  if (!saved)
    return 0;

  player = ([]);
  player["display_name"] = player_name;
  player["brief"] = 0;
  player["last_played"] = 0;
  default_chapter = CHAPTER_D->query_latest_chapter();

  if (default_chapter != "") {
    player["current_chapter"] = default_chapter;
    player["unlocked_chapters"] = ({ default_chapter });
  }

  path = player_file(username, player_name);

  if (path == "")
    return 0;

  ensure_account_dir(username);

  return save_data(path, player);
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

void record_player_login(string username, string player_name) {
  mapping player;
  string path;

  if (!account_exists(username))
    return;

  path = player_file(username, player_name);
  player = load_data(path);

  if (!mapp(player))
    return;

  player["last_played"] = time();

  save_data(path, player);
}
