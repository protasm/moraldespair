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
    long_desc = "You stand within the high, vaulted shadows of the Sanctuary. Two centuries ago, this hall was a beacon of hope for die-hard adventurers. Now, the air is cold and tastes of stagnant incense. The glory that once beckoned is long forgotten, replaced by a hollow silence that whispers of a great decay.";
    dest_dir = ({
        "domain/original/area/vesla/room228", "south",
        "domain/original/area/vesla/lounge", "up",
        "domain/original/area/vesla/portal", "down",
    });
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

    string result;

    result = long_desc;

    result += "\n\nYou feel a STRONG urge to... you can't recall?";
    result += "\n\nA massive clock looms overhead, its pendulum swinging in a long, lazy arc.";
    result += "\n\nThere are exits up, down, and south.\n";
 
    result = "/daemon/text_d"->format_text(result, 80);

    write(result + "\n");

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

