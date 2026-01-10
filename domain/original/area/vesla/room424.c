inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Fighter's Guild";
    long_desc = "Fighter's Guild";
    dest_dir = ({
        "domain/original/area/vesla/room156", "west",
    });
}
