inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "MD Banking";
    long_desc = "PHSAE0: player owned bank guild";
    dest_dir = ({
        "domain/original/area/vesla/room217", "east",
    });
}

