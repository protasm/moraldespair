inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Folio depository";
    long_desc = "Folio depository.\n";
    dest_dir = ({
        "domain/original/area/pylus/room1378", "west",
    });
}
