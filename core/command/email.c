/*
 * Master Summary:
 * Purpose:
 *   Implements the object behavior defined in core/command/email.c.
 * Approach:
 *   Uses explicit LPC methods with straightforward control flow so
 *   behavior stays predictable, debuggable, and easy to evolve.
 * Dependencies:
 *   - inherit "/core/command/command";
 */

inherit "/core/command/command";

/* Method Summary:
 * Purpose:
 *   Handles create for this object.
 * Parameters:
 *   - none
 * Approach:
 *   Validates inputs and executes explicit local logic for create.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   void result from create.
 */
void create() {
  ::create();

  set_category("Account");
  set_help_text(
    "Usage: email or email <address>\n"
    "Show or set the account email address.\n"
  );
}

/* Method Summary:
 * Purpose:
 *   Handles main for this object.
 * Parameters:
 *   - string arg
 * Approach:
 *   Validates inputs and executes explicit local logic for main.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   int result from main.
 */
int main(string arg) {
  object avatar;
  object account;
  string email;
  int saved;

  avatar = current_avatar();

  if (!is_avatar(avatar))
    return 0;

  account = avatar_account(avatar);

  if (!objectp(account))
    return 0;

  if (!function_exists("email", account))
    return 0;

  if (!function_exists("set_email", account))
    return 0;

  if (!stringp(arg))
    arg = "";

  email = trim(arg);

  if (email == "") {
    email = account->email();

    if (email == "")
      write("No email is set for this account.\n");
    else
      write("Account email: " + email + "\n");

    return 1;
  }

  saved = account->set_email(email);

  if (!saved)
    write("Unable to update account email.\n");
  else
    write("Account email updated.\n");

  return 1;
}
