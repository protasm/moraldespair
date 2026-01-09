inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Broken Corner of a Western Road and a Stone Avenue";
    long_desc = "Two ruined streets meet among rubble and scorched debris. The "
        + "corner is choked with broken stone and ash.\n";
    dest_dir = ({
        "domain/original/area/vesla/room134", "west",
        "domain/original/area/vesla/room132", "east",
        "domain/original/area/vesla/room135", "south",
    });
}
