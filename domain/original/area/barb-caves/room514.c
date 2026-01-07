inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "You begin to climb into the pit, and the descent seems simple enough.";
    long_desc = "You begin to climb into the pit, and the descent seems simple enough.\n";
    dest_dir = ({ });
}
