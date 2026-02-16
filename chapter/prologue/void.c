string short() {
    return "The void";
}

void long() {
    object avatar;

    avatar = current_avatar();

    if (!is_avatar(avatar))
        return;

    avatar_experience(avatar, short() + ".\n");
    avatar_experience(avatar,
      "You come to the void if you fall out of a room, and have nowhere to "
      "go.\n");
    avatar_experience(avatar,
      "Give the command 'sanctuary', and you will return to the "
      "Sanctuary.\n");
    avatar_experience(avatar, "\nYou are transferred to the Sanctuary...\n");
    avatar->move_player("X#chapter/prologue/area/ruined/sanctuary");
}

void init() {
    add_action("sanctuary", "sanctuary");
}

int sanctuary() {
    object avatar;

    avatar = current_avatar();

    if (!is_avatar(avatar))
        return 0;

    avatar->move_player("away#chapter/prologue/area/ruined/sanctuary");

    return 1;
}

void reset(int arg) {
    if (arg)
        return;
    set_light(1);
}

int id(string str) {
    return str == "void";
}
