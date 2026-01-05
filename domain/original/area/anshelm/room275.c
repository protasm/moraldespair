inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Before the Anshelm Town Gate";
    long_desc = "Before the Anshelm Town Gate.\n";
    dest_dir = ({
        "domain/original/area/anshelm/room274", "south",
        "domain/original/area/roadway/room42", "exit",
    });
}
