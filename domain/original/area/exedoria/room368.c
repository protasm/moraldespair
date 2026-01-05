inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Eidolon Warlords";
    long_desc = "Eidolon Warlords.\n";
    dest_dir = ({
        "domain/original/area/exedoria/room288", "north",
    });
}
