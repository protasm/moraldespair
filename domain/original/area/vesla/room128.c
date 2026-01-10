inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Westroad, The Entrance to the Old City.";
    long_desc = "Westroad, The Entrance to the Old City.\n";
    dest_dir = ({
        "domain/original/area/vesla/room129", "west",
        "domain/original/area/vesla/room127", "east",
        "domain/original/area/vesla/room881", "north",
    });
}
