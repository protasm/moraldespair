inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Servants Quarters";
    long_desc = "Servants Quarters.\n";
    dest_dir = ({
        "domain/original/area/candera/room68", "west",
    });
}
