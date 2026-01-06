inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Foyer";
    long_desc = "Foyer.\n";
    dest_dir = ({
        "domain/original/area/pylus/room1235", "west",
    });
}
