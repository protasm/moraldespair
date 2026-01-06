inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Porch";
    long_desc = "Porch.\n";
    dest_dir = ({
        "domain/original/area/pylus/room1215", "northeast",
    });
}
