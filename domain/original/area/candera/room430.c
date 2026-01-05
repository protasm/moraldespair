inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Scribe";
    long_desc = "Scribe.\n";
    dest_dir = ({
        "domain/original/area/candera/room65", "east",
    });
}
