inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Burned Run";
    long_desc = "A crooked passage threads between leaning fragments of masonry. Loose stones shift with each step, exposing darker layers below. The place feels picked clean, stripped of timber and metal.";
    dest_dir = ({
        "domain/original/area/candera/room29", "east",
        "domain/original/area/candera/room31", "west",
    });
}
