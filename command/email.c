inherit "/core/command";

void create() {
  ::create();

  set_category("Account");
  set_help_text(
    "Usage: email or email <address>\n"
    "Show or set the account email address.\n"
  );
}

int main(string arg) {
  object player;
  string email;
  int saved;

  player = this_player();

  if (!objectp(player))
    return 0;

  if (!stringp(arg))
    arg = "";

  email = trim(arg);

  if (email == "") {
    email = player->query_account_email();

    if (email == "")
      write("No email is set for this account.\n");
    else
      write("Account email: " + email + "\n");

    return 1;
  }

  saved = player->set_account_email(email);

  if (!saved)
    write("Unable to update account email.\n");
  else
    write("Account email updated.\n");

  return 1;
}
