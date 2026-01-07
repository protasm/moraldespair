inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Ruined Entrance to the Old City";
    long_desc = "A battered arch and toppled stones mark the entrance into Vesla's ruins. The road ahead is cracked and choked with debris.\n";
    dest_dir = ({
        "domain/original/area/vesla/room128", "west",
        "domain/original/area/vesla/room126", "east",
        "domain/original/area/vesla/room878", "north",
    });
}
