inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Scorched Chamber";
    long_desc = "Char marks crawl across the walls, and fused debris crunches underfoot. Heat-scarred stone and warped metal hint at a terrible blaze.\n";
    dest_dir = ({
        "domain/original/area/vesla/room183", "east",
    });
}
