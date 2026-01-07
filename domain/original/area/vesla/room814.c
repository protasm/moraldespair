inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Shattered Walk";
    long_desc = "A brittle silence fills this ruined space. Burnt stone and warped metal gleam faintly, scarred by intense flames.\n";
    dest_dir = ({
        "domain/original/area/vesla/room796", "north",
    });
}
