inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Wash area";
    long_desc = "Wash area\n";
    dest_dir = ({
        "domain/original/area/vesla/room778", "southeast",
        "domain/original/area/vesla/room777", "south",
    });
}
