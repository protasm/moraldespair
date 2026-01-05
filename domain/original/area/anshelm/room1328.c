inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Eastern end of Geld Strasse";
    long_desc = "Eastern end of Geld Strasse.\n";
    dest_dir = ({
        "domain/original/area/anshelm/room1329", "east",
        "domain/original/area/anshelm/room281", "west",
    });
}
