#include <globals.h>

inherit "/inherit/base.c";

string account_name;
string avatar_name;

string normalize_key(string value) {
  if (!stringp(value))
    return "";

  return lower_case(trim(value));
}

string avatar_file_path() {
  string username;
  string avatar;

  username = normalize_key(account_name);
  avatar = normalize_key(avatar_name);

  if (username == "" || avatar == "")
    return "";

  return "/a/" + username + "/" + avatar + ".o";
}

mapping load_avatar_data() {
  mapping avatar;
  string path;
  string raw;

  path = avatar_file_path();

  if (path == "")
    return 0;

  if (file_size(path) <= 0)
    return 0;

  raw = read_file(path);

  if (!stringp(raw))
    return 0;

  avatar = restore_variable(raw);

  if (!mapp(avatar))
    return 0;

  return avatar;
}

int save_avatar_data(mapping avatar) {
  string path;
  string raw;

  if (!mapp(avatar))
    return 0;

  path = avatar_file_path();

  if (path == "")
    return 0;

  raw = save_variable(avatar);

  rm(path);

  return write_file(path, raw);
}

string query_account() {
  return account_name;
}

void set_account(string new_account) {
  account_name = new_account;

  return;
}

string query_name() {
  return avatar_name;
}

void set_name(string new_name) {
  avatar_name = new_name;

  return;
}

string query_display_name() {
  mapping avatar;

  avatar = load_avatar_data();

  if (!mapp(avatar))
    return "";

  return avatar["display_name"];
}

int set_display_name(string new_display_name) {
  mapping avatar;

  if (!stringp(new_display_name))
    return 0;

  avatar = load_avatar_data();

  if (!mapp(avatar))
    return 0;

  avatar["display_name"] = new_display_name;

  return save_avatar_data(avatar);
}

int query_brief() {
  mapping avatar;

  avatar = load_avatar_data();

  if (!mapp(avatar))
    return 0;

  return avatar["brief"];
}

int set_brief(int state) {
  mapping avatar;

  avatar = load_avatar_data();

  if (!mapp(avatar))
    return 0;

  if (state)
    avatar["brief"] = 1;
  else
    avatar["brief"] = 0;

  return save_avatar_data(avatar);
}

int toggle_brief() {
  mapping avatar;
  int brief;

  avatar = load_avatar_data();

  if (!mapp(avatar))
    return 0;

  brief = avatar["brief"];

  if (brief)
    avatar["brief"] = 0;
  else
    avatar["brief"] = 1;

  if (!save_avatar_data(avatar))
    return 0;

  return avatar["brief"];
}

int query_last_played() {
  mapping avatar;

  avatar = load_avatar_data();

  if (!mapp(avatar))
    return 0;

  return avatar["last_played"];
}

int set_last_played(int last_played) {
  mapping avatar;

  avatar = load_avatar_data();

  if (!mapp(avatar))
    return 0;

  avatar["last_played"] = last_played;

  return save_avatar_data(avatar);
}
