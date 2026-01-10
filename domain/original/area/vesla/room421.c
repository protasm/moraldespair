inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Mage's Guild";
    long_desc = "Mage's Guild";
    dest_dir = ({
        "domain/original/area/vesla/room132", "north",
    });
}
