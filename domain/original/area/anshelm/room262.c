inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Geld Strasse";
    long_desc = "Geld Strasse.\n";
    dest_dir = ({
        "domain/original/area/anshelm/room261", "east",
        "domain/original/area/anshelm/room263", "west",
    });
}
