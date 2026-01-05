inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "<> Aladrin escapes reality and falls into Moral Decay. <>";
    long_desc = "<> Aladrin escapes reality and falls into Moral Decay. <>.\n";
    dest_dir = ({
        "domain/original/area/vesla/room874", "down",
        "domain/original/area/vesla/room871", "up",
    });
}
