inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Morbid Curiosity";
    long_desc = "Morbid Curiosity.\n";
    dest_dir = ({
        "domain/original/area/candera/room72", "north",
        "domain/original/area/candera/room64", "east",
    });
}
