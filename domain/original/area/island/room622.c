inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "A Bloody Arena.";
    long_desc = "A Bloody Arena..\n";
    dest_dir = ({ });
}
