inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "The hermit says: Is there anything you would like to talk about?";
    long_desc = "The hermit says: Is there anything you would like to talk about?.\n";
    dest_dir = ({ });
}
