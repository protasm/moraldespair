/*
 * Master Summary:
 * Purpose:
 *   Implements the object behavior defined in core/account/account.c.
 * Approach:
 *   Uses explicit LPC methods with straightforward control flow so
 *   behavior stays predictable, debuggable, and easy to evolve.
 * Dependencies:
 *   - #include <globals.h>
 *   - #include "account.h"
 */

#include <globals.h>

#include "account.h"

string account_username;

/* Method Summary:
 * Purpose:
 *   Handles username for this object.
 * Parameters:
 *   - none
 * Approach:
 *   Validates inputs and executes explicit local logic for username.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   string result from username.
 */
string username() {
  return account_username;
}

/* Method Summary:
 * Purpose:
 *   Handles set_username for this object.
 * Parameters:
 *   - string new_username
 * Approach:
 *   Validates inputs and executes explicit local logic for set_username.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   void result from set_username.
 */
void set_username(string new_username) {
  account_username = normalize_key(new_username);
}

/* Method Summary:
 * Purpose:
 *   Handles normalize_key for this object.
 * Parameters:
 *   - string value
 * Approach:
 *   Validates inputs and executes explicit local logic for normalize_key.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   string result from normalize_key.
 */
string normalize_key(string value) {
  if (!stringp(value))
    return "";

  return lower_case(trim(value));
}

/* Method Summary:
 * Purpose:
 *   Handles account_file_path for this object.
 * Parameters:
 *   - none
 * Approach:
 *   Validates inputs and executes explicit local logic for account_file_path.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   string result from account_file_path.
 */
string account_file_path() {
  if (account_username == "")
    return "";

  return "/a/" + account_username + "/account.o";
}

/* Method Summary:
 * Purpose:
 *   Handles load_account_data for this object.
 * Parameters:
 *   - none
 * Approach:
 *   Validates inputs and executes explicit local logic for load_account_data.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   mapping result from load_account_data.
 */
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

/* Method Summary:
 * Purpose:
 *   Handles save_account_data for this object.
 * Parameters:
 *   - mapping account
 * Approach:
 *   Validates inputs and executes explicit local logic for save_account_data.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   int result from save_account_data.
 */
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

/* Method Summary:
 * Purpose:
 *   Handles handle_command for this object.
 * Parameters:
 *   - string verb, string arg
 * Approach:
 *   Validates inputs and executes explicit local logic for handle_command.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   int result from handle_command.
 */
int handle_command(string verb, string arg) {
  string command_path;
  object command_object;
  int handled;

  handled = 0;
  command_path = COMMAND_PREFIX + verb;

  if (file_size(command_path + ".c") >= 0) {
    command_object = load_object(command_path);

    if (objectp(command_object))
      handled = call_other(command_object, "main", arg);
  }

  return handled;
}

/* Method Summary:
 * Purpose:
 *   Handles email for this object.
 * Parameters:
 *   - none
 * Approach:
 *   Validates inputs and executes explicit local logic for email.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   string result from email.
 */
string email() {
  mapping account;

  account = load_account_data();

  if (!mapp(account))
    return "";

  return account["email"];
}

/* Method Summary:
 * Purpose:
 *   Handles set_email for this object.
 * Parameters:
 *   - string new_email
 * Approach:
 *   Validates inputs and executes explicit local logic for set_email.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   int result from set_email.
 */
int set_email(string new_email) {
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

/* Method Summary:
 * Purpose:
 *   Handles password_hash for this object.
 * Parameters:
 *   - none
 * Approach:
 *   Validates inputs and executes explicit local logic for password_hash.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   string result from password_hash.
 */
string password_hash() {
  mapping account;
  string hash_value;

  account = load_account_data();

  if (!mapp(account))
    return "";

  hash_value = account["password_hash"];

  if (!stringp(hash_value) || hash_value == "")
    hash_value = account["password"];

  if (!stringp(hash_value))
    return "";

  return hash_value;
}

/* Method Summary:
 * Purpose:
 *   Handles set_password_hash for this object.
 * Parameters:
 *   - string new_hash
 * Approach:
 *   Validates inputs and executes explicit local logic for set_password_hash.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   int result from set_password_hash.
 */
int set_password_hash(string new_hash) {
  mapping account;

  if (!stringp(new_hash))
    return 0;

  account = load_account_data();

  if (!mapp(account))
    return 0;

  account["password_hash"] = new_hash;

  return save_account_data(account);
}

/* Method Summary:
 * Purpose:
 *   Handles players for this object.
 * Parameters:
 *   - none
 * Approach:
 *   Validates inputs and executes explicit local logic for players.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   string result from players.
 */
string *players() {
  mapping account;
  string *players;

  account = load_account_data();

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

/* Method Summary:
 * Purpose:
 *   Handles set_players for this object.
 * Parameters:
 *   - string *players
 * Approach:
 *   Validates inputs and executes explicit local logic for set_players.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   int result from set_players.
 */
int set_players(string *players) {
  mapping account;

  if (!pointerp(players))
    return 0;

  account = load_account_data();

  if (!mapp(account))
    return 0;

  account["players"] = players;
  account["avatars"] = players;

  return save_account_data(account);
}

/* Method Summary:
 * Purpose:
 *   Handles last_login for this object.
 * Parameters:
 *   - none
 * Approach:
 *   Validates inputs and executes explicit local logic for last_login.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   int result from last_login.
 */
int last_login() {
  mapping account;

  account = load_account_data();

  if (!mapp(account))
    return 0;

  return account["last_login"];
}

/* Method Summary:
 * Purpose:
 *   Handles set_last_login for this object.
 * Parameters:
 *   - int last_login
 * Approach:
 *   Validates inputs and executes explicit local logic for set_last_login.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   int result from set_last_login.
 */
int set_last_login(int last_login) {
  mapping account;

  account = load_account_data();

  if (!mapp(account))
    return 0;

  account["last_login"] = last_login;

  return save_account_data(account);
}
