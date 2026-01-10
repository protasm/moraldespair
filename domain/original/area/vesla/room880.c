inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Old Adventurer's Guild";
    long_desc = "Old Adventurer's Guild";
    dest_dir = ({
        "domain/original/area/vesla/room126", "north",
    });
}
