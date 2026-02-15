#include "/core/daemon/account_d.h"
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

string username_by_email(string email) {
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

    if (account["email"] == normalized) {
      if (stringp(account["account_name"]) && account["account_name"] != "")
        return account["account_name"];

      if (stringp(account["username"]))
        return account["username"];
    }
  }

  return "";
}

string password_hash(string username) {
  mapping account;
  string hash_value;

  username = normalize_key(username);
  account = load_data(account_file(username));

  if (!mapp(account))
    return "";

  hash_value = account["password_hash"];

  if (!stringp(hash_value) || hash_value == "")
    hash_value = account["password"];

  if (!stringp(hash_value))
    return "";

  return hash_value;
}

string display_name(string username) {
  mapping account;
  string display;

  username = normalize_key(username);
  account = load_data(account_file(username));

  if (!mapp(account))
    return "";

  display = account["display_name"];

  if (!stringp(display))
    return "";

  return display;
}

string *players(string username) {
  mapping account;
  string *player_list;

  username = normalize_key(username);
  account = load_data(account_file(username));

  if (!mapp(account))
    return ({});

  player_list = account["players"];

  if (!pointerp(player_list)) {
    player_list = account["avatars"];

    if (!pointerp(player_list))
      return ({});
  }

  return player_list;
}

string last_played_player(string username) {
  string *player_list;
  string player_name;
  string player_path;
  mapping player_data;
  string latest_player;
  int latest_played;
  int played_at;
  int i;

  username = normalize_key(username);

  if (username == "")
    return "";

  player_list = players(username);

  if (!pointerp(player_list) || sizeof(player_list) == 0)
    return "";

  latest_player = "";
  latest_played = 0;

  for (i = 0; i < sizeof(player_list); i++) {
    player_name = player_list[i];
    player_path = player_file(username, player_name);

    if (player_path == "")
      continue;

    player_data = load_data(player_path);

    if (!mapp(player_data))
      continue;

    played_at = player_data["last_played"];

    if (!intp(played_at))
      played_at = 0;

    if (played_at <= 0)
      continue;

    if (played_at > latest_played) {
      latest_played = played_at;
      latest_player = player_name;
    }
  }

  return latest_player;
}

int max_players_per_account() {
  return 3;
}

int player_slots_remaining(string username) {
  string *player_list;
  int remaining;

  player_list = players(username);
  remaining = max_players_per_account() - sizeof(player_list);

  if (remaining < 0)
    remaining = 0;

  return remaining;
}

int player_exists(string username, string player_name) {
  string *player_list;
  string normalized;
  int i;

  player_list = players(username);
  normalized = normalize_key(player_name);

  for (i = 0; i < sizeof(player_list); i++) {
    if (normalize_key(player_list[i]) == normalized)
      return 1;
  }

  return 0;
}

int create_account(string username, string display_name, string email,
                   string password_hash) {
  mapping account;
  string account_name;
  int saved;

  account_name = normalize_key(username);

  if (!stringp(email))
    email = "";

  email = normalize_key(email);

  if (account_name == "")
    return 0;

  if (account_exists(account_name))
    return 0;

  if (!stringp(display_name) || display_name == "")
    display_name = capitalize(account_name);

  account = ([]);
  account["account_name"] = account_name;
  account["display_name"] = display_name;
  account["email"] = email;
  account["password_hash"] = password_hash;
  account["players"] = ({});
  account["avatars"] = ({});
  account["last_login"] = 0;

  ensure_account_dir(account_name);
  saved = save_data(account_file(account_name), account);

  return saved;
}

int add_player(string username, string player_name) {
  mapping account;
  string *players;
  mapping player;
  string path;
  string default_chapter;
  int slots_remaining;
  int saved;

  if (!account_exists(username))
    return 0;

  slots_remaining = player_slots_remaining(username);

  if (slots_remaining <= 0)
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
  default_chapter = CHAPTER_D->latest_chapter();

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
