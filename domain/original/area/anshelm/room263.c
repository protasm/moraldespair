inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Western end of Geld Strasse";
    long_desc = "Western end of Geld Strasse.\n";
    dest_dir = ({
        "domain/original/area/anshelm/room262", "east",
    });
}
