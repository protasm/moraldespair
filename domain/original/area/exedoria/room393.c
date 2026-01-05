inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Guard Tower Entrance";
    long_desc = "Guard Tower Entrance.\n";
    dest_dir = ({
        "domain/original/area/exedoria/room305", "south",
    });
}
