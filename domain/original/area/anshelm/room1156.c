inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Gatehouse Armoury";
    long_desc = "Gatehouse Armoury.\n";
    dest_dir = ({
        "domain/original/area/anshelm/room1155", "up",
    });
}
