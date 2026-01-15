inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Magoo's Bookstore";
    long_desc = "PHASE0: NPC-owned business";
    dest_dir = ({
        "domain/original/area/vesla/room191", "north",
    });
}

