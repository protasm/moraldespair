inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "burned run";
    long_desc = "A crooked passage threads between leaning fragments of masonry. Loose stones shift with each step, exposing darker layers below.\n\nThe place feels picked clean, stripped of timber and metal.\n";
    dest_dir = ({
        "domain/original/area/candera/room58", "east",
    });
}
