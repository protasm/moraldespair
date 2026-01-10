inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Eastern tower observatory";
    long_desc = "Eastern tower observatory\n";
    dest_dir = ({
        "domain/original/area/vesla/room763", "northeast",
    });
}
