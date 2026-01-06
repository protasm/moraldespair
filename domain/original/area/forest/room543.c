inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "A dark forest";
    long_desc = "A dark forest.\n";
    dest_dir = ({
        "domain/original/area/forest/room542", "southwest",
        "domain/original/area/forest/room544", "northeast",
        "domain/original/area/forest/room546", "east",
        "domain/original/area/forest/room547", "south",
    });
}
