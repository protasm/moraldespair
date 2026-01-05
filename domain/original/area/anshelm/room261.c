inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Geld Strasse";
    long_desc = "Geld Strasse.\n";
    dest_dir = ({
        "domain/original/area/anshelm/room260", "east",
        "domain/original/area/anshelm/room262", "west",
    });
}
