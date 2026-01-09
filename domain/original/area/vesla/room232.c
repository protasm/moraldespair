inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Scorched Chamber";
    long_desc = "Char marks crawl across the walls, and fused debris crunches "
        + "underfoot. Heat-scarred stone and warped metal hint at a "
        + "terrible blaze.\n";
    dest_dir = ({
        "domain/original/area/vesla/room226", "south",
        "domain/original/area/vesla/room227", "west",
        "domain/original/area/vesla/room173", "east",
        "domain/original/area/vesla/room234", "north",
    });
}
