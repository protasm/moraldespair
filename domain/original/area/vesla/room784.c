inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Split Rails";
    long_desc = "Split rails mark the stall lines, some fallen flat into the dirt. The ground is rutted and cold, with a sour odor of rot.";
    dest_dir = ({
        "domain/original/area/vesla/room775", "north",
    });
}

