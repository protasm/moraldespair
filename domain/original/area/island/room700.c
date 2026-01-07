inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Bedchamber";
    long_desc = "Bedchamber.\n";
    dest_dir = ({
        "domain/original/area/island/room701", "east",
        "domain/original/area/island/room699", "west",
    });
}
