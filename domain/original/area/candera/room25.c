inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Scarred Hollow";
    long_desc = "The route skirts a collapsed chamber, its edge cut clean by fire. Hollow window frames stare out, their ledges buried in dust.";
    dest_dir = ({
        "domain/original/area/candera/room24", "east",
        "domain/original/area/candera/room26", "west",
    });
}
