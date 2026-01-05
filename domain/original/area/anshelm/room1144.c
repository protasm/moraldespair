inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Gatehouse Mess Hall";
    long_desc = "Gatehouse Mess Hall.\n";
    dest_dir = ({
        "domain/original/area/anshelm/room1145", "east",
        "domain/original/area/anshelm/room1138", "west",
    });
}
