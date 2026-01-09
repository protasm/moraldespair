inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Shattered Cut";
    long_desc = "The ground levels out into a broad, empty spread of fractured flagstone. Small\npits and cracks show where repeated blows split the surface.\n";
    dest_dir = ({
        "domain/original/area/candera/room986", "north",
        "domain/original/area/candera/room974", "south",
        "domain/original/area/candera/room15", "west",
    });
}
