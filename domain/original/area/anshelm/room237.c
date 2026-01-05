inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Southern end of Rue du Nord";
    long_desc = "Southern end of Rue du Nord.\n";
    dest_dir = ({
        "domain/original/area/anshelm/room1135", "southwest",
        "domain/original/area/anshelm/room236", "south",
        "domain/original/area/anshelm/room1154", "southeast",
        "domain/original/area/anshelm/room238", "north",
    });
}
