inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Guard Post for Gnome Embassy";
    long_desc = "Guard Post for Gnome Embassy.\n";
    dest_dir = ({
        "domain/original/area/exedoria/room316", "south",
        "domain/original/area/exedoria/room926", "north",
    });
}
