inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Scarred Hollow";
    long_desc = "The route skirts a collapsed chamber, its edge cut clean by fire. Hollow window\nframes stare out, their ledges buried in dust.\n";
    dest_dir = ({
        "domain/original/area/candera/room973", "south",
    });
}
