inherit "/core/command/command";

void create() {
  ::create();

  set_category("Communication");
  set_help_text(
    "Usage: say <message>\n"
    "Speak to everyone in your current location.\n"
    "Your words are heard by anyone nearby.\n"
  );
}

int main(string arg) {
  object avatar;
  object env;
  string spoken_text;

  avatar = current_avatar();

  if (!is_avatar(avatar))
    return 0;

  if (!stringp(arg))
    arg = "";

  spoken_text = trim(arg);

  if (spoken_text == "") {
    avatar_experience(avatar, "Say what?\n");
    return 1;
  }

  avatar_experience(avatar, "You say, '" + spoken_text + "'\n");
  env = environment(avatar);

  if (!objectp(env))
    return 1;

  EXPERIENCE_D->emit_speech_event(avatar, env, spoken_text);

  return 1;
}
