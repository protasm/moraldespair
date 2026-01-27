#include <globals.h>

#include "account.h"

inherit "/inherit/base.c";

string name, account_name;
object curr_avatar;

string normalize_key(string value) {
  if (!stringp(value))
    return "";

  return lower_case(trim(value));
}

string account_file_path() {
  string username;

  username = normalize_key(account_name);

  if (username == "")
    return "";

  return "/a/" + username + "/account.o";
}

mapping load_account_data() {
  mapping account;
  string path, raw;

  path = account_file_path();

  if (path == "")
    return 0;

  if (file_size(path) <= 0)
    return 0;

  raw = read_file(path);

  if (!stringp(raw))
    return 0;

  account = restore_variable(raw);

  if (!mapp(account))
    return 0;

  return account;
}

int save_account_data(mapping account) {
  string path, raw;

  if (!mapp(account))
    return 0;

  path = account_file_path();

  if (path == "")
    return 0;

  raw = save_variable(account);

  rm(path);

  return write_file(path, raw);
}

int try_command(string prefix, string verb, string arg) {
  string command_path;
  object command_object;
  int handled;

  handled = 0;
  command_path = prefix + verb;

  if (file_size(command_path + ".c") >= 0) {
    command_object = load_object(command_path);

    if (objectp(command_object))
      handled = call_other(command_object, "main", arg);
  }

  return handled;
}

int handle_command(string verb, string arg) {
  int handled;

  handled = try_command(COMMAND_PREFIX, verb, arg);

  if (handled)
    return 1;

  return 0;
}

string query_name() {
  return name;
}

void set_name(string new_name) {
  name = new_name;

  return;
}

string query_account() {
  return account_name;
}

void set_account(string new_account) {
  account_name = new_account;

  return;
}

object query_curr_avatar() {
  return curr_avatar;
}

void set_curr_avatar(object avatar) {
  curr_avatar = avatar;

  return;
}

string query_account_display_name() {
  mapping account;

  account = load_account_data();

  if (!mapp(account))
    return "";

  return account["display_name"];
}

int set_account_display_name(string new_display_name) {
  mapping account;

  if (!stringp(new_display_name))
    return 0;

  account = load_account_data();

  if (!mapp(account))
    return 0;

  account["display_name"] = new_display_name;

  return save_account_data(account);
}

string query_account_email() {
  mapping account;

  account = load_account_data();

  if (!mapp(account))
    return "";

  return account["email"];
}

int set_account_email(string new_email) {
  mapping account;
  string normalized;

  if (!stringp(new_email))
    return 0;

  normalized = normalize_key(new_email);

  if (normalized == "")
    return 0;

  account = load_account_data();

  if (!mapp(account))
    return 0;

  account["email"] = normalized;

  return save_account_data(account);
}

string query_account_password_hash() {
  mapping account;

  account = load_account_data();

  if (!mapp(account))
    return "";

  return account["password_hash"];
}

int set_account_password_hash(string new_hash) {
  mapping account;

  if (!stringp(new_hash))
    return 0;

  account = load_account_data();

  if (!mapp(account))
    return 0;

  account["password_hash"] = new_hash;

  return save_account_data(account);
}

string *query_account_avatars() {
  mapping account;
  string *avatars;

  account = load_account_data();

  if (!mapp(account))
    return ({});

  avatars = account["avatars"];

  if (!pointerp(avatars))
    return ({});

  return avatars;
}

int set_account_avatars(string *avatars) {
  mapping account;

  if (!pointerp(avatars))
    return 0;

  account = load_account_data();

  if (!mapp(account))
    return 0;

  account["avatars"] = avatars;

  return save_account_data(account);
}

int query_account_last_login() {
  mapping account;

  account = load_account_data();

  if (!mapp(account))
    return 0;

  return account["last_login"];
}

int set_account_last_login(int last_login) {
  mapping account;

  account = load_account_data();

  if (!mapp(account))
    return 0;

  account["last_login"] = last_login;

  return save_account_data(account);
}
