inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Frenchie's Cafe";
    long_desc = "Frenchie's Cafe.\n";
    dest_dir = ({
        "domain/original/area/vesla/room191", "south",
    });
}
