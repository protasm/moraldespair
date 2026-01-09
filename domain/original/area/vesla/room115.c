inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Ruined Gate to the Wilderness";
    long_desc = "The once-tall gatehouse is split and blackened, its stones "
        + "scattered across the approach. Ash and rubble mark the way "
        + "into the dead city.\n";
    dest_dir = ({
        "domain/original/area/vesla/room116", "west",
	"domain/original/area/roadway/room14", "exit",
    });
}

/*
void init() {
    ::init();

    add_action("block_exit", "exit");
}

int block_exit() {
    write("The ruined gate has collapsed; the way to the wilderness is impassable.\n");

    return 1;
}
*/
