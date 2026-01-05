inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Lizard Skin Trader";
    long_desc = "Lizard Skin Trader.\n";
    dest_dir = ({
        "domain/original/area/candera/room60", "east",
    });
}
