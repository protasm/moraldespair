inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Wind-Scoured Reach";
    long_desc = "The way pinches tight, then opens again into scattered foundations. Ash and grit collect in corners, damped by occasional trickles.";
    dest_dir = ({
        "chapter/prologue/area/sunken/room30", "east",
        "chapter/prologue/area/sunken/room32", "west",
    });
}
