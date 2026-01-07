inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Broken Westroad, Entrance to the Old City";
    long_desc = "Westroad begins here amid collapsed paving and scattered masonry. The way into the old city lies ruined and abandoned.\n";
    dest_dir = ({
        "domain/original/area/vesla/room129", "west",
        "domain/original/area/vesla/room127", "east",
        "domain/original/area/vesla/room881", "north",
    });
}
