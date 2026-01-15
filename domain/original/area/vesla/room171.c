inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Wall Road";
    long_desc = "The wall runs north and south beside a straight stretch of empty\n"
              + "road, its cobbles split by weeds and grit. The silence here is\n"
              + "only broken by a faint, steady draft along the stone.\n";
    dest_dir = ({
        "domain/original/area/vesla/room170", "west",
    });
}
