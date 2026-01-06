inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Sanity's Requiem";
    long_desc = "Sanity's Requiem.\n";
    dest_dir = ({
        "domain/original/area/pylus/room1215", "northwest",
    });
}
