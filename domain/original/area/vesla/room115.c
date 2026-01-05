inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "The Gate to the Wilderness";
    long_desc = "The Gate to the Wilderness.\n";
    dest_dir = ({
        "domain/original/area/vesla/room116", "west",
	"domain/original/area/roadway/room14", "exit",
    });
}
