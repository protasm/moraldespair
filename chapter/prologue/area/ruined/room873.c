inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "<> Aladrin escapes reality and falls into Moral Decay. <>";
    long_desc = "<> Aladrin escapes reality and falls into Moral Decay. <>";
    dest_dir = ({
        "chapter/prologue/area/ruined/room874", "down",
        "chapter/prologue/area/ruined/room871", "up",
    });
}
