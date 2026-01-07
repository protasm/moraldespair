inherit "room/room";

int reboot_time, time_from_reset, last_reset_cycle;
int list_length;

void reset(int arg) {
    if (time_from_reset)
        last_reset_cycle = time() - time_from_reset;

    time_from_reset = time();

    if (arg)
        return;

    set_light(1);

    reboot_time = time();
    short_desc = "Sanctuary";
    long_desc = "Sanctuary.\n";
    dest_dir = ({
        "domain/original/area/vesla/room228", "south",
	"domain/original/area/vesla/room893", "up",
	"domain/original/area/vesla/portal", "down",
    });
}

void init() {
    ::init();

    add_action("close_portal_room", "down");
}

int close_portal_room(string arg) {
    write("The portal room is closed.\n");

    return 1;   /* block movement */
}


void show_clock() {
    int i, j;

    write("The clock shows ");

    i = time() - reboot_time;
    j = i / 60 / 60 / 24;

    if (j == 1)
        write("1 day ");
    else if (j > 0)
        write(j + " days ");

    i -= j * 60 * 60 * 24;
    j = i / 60 / 60;

    if (j == 1)
        write("1 hour ");
    else if (j > 0)
        write(j + " hours ");

    i -= j * 60 * 60;
    j = i / 60;

    if (j == 1)
        write("1 minute ");
    else if (j > 0)
        write(j + " minutes ");

    i -= j * 60;

    if (i == 1)
        write("1 second");
    else if (i > 0)
        write(i + " seconds");

    write("\n");

    if (this_player()->query_level() < 20)
        return;

    write("Time since reset is " + (time() - time_from_reset) +
      " seconds.\n");

    if (last_reset_cycle)
        write("Reset cycle: " + last_reset_cycle + "\n");

    write("Free block list length: " + list_length + "\n");

    return;
}

void long(string str) {
    if (str == "clock") {
        show_clock();

        return;
    }

    write("Sanctuary\n");
    write("There is a clock here.\n");
    write("There are exits up, down, and south.\n");

    return;
}

int id(string str) {
    return str == "clock";
}

int pray() {
    return this_player()->remove_ghost();
}

int prevent_look_at_inv(string str) {
    return str != 0;
}

int query_drop_castle() {
    return 1;
}
