inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "Hollow Park";
    long_desc = "The ground dips where a pond once spread, now a dish of silt and weeds.\n"
              + "Scattered paving stones and toppled posts mark the forgotten walkway.\n";
    dest_dir = ({
        "domain/original/area/vesla/room226", "south",
        "domain/original/area/vesla/room227", "west",
        "domain/original/area/vesla/room173", "east",
        "domain/original/area/vesla/room234", "north",
    });
}
