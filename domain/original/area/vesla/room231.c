inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "Withered Park";
    long_desc = "Dry shrubs crowd a cracked path, and pale trunks stand stripped of bark. Old\n"
              + "lantern hooks hang crooked from a low wall, black with rust.\n";
    dest_dir = ({
        "domain/original/area/vesla/room230", "south",
        "domain/original/area/vesla/room796", "west",
        "domain/original/area/vesla/room227", "east",
        "domain/original/area/vesla/room426", "north",
    });
}
