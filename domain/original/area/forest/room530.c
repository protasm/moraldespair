inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "The start of a forest path";
    long_desc = "The start of a forest path.\n";
    dest_dir = ({
        "domain/original/area/forest/room529", "southwest",
        "domain/original/area/forest/room531", "northeast",
        "domain/original/area/forest/room532", "northwest",
    });
}
