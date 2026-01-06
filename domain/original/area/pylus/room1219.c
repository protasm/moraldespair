inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Triage";
    long_desc = "Triage.\n";
    dest_dir = ({
        "domain/original/area/pylus/room1214", "west",
        "domain/original/area/pylus/room1220", "north",
    });
}
