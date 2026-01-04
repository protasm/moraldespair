string short() {
    return "The void";
}

void long() {
    write(short() + ".\n");
    write("You come to the void if you fall out of a room, and have nowhere to go.\n");
    write("Give the command 'sanctuary', and you will return to the Sanctuary.\n");
    write("\nYou are transferred to the Sanctuary...\n");
    this_player()->move_player("X#domain/original/area/vesla/sanctuary");
}

void init() {
    add_action("sanctuary", "sanctuary");
}

int sanctuary() {
    this_player()->move_player("away#domain/original/area/vesla/sanctuary");
    return 1;
}

void reset(int arg)
{
    if (arg)
	return;
    set_light(1);
}

int id(string str) { return str == "void"; }
