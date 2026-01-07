inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Desecrated Crossing of Via Sacra and River Street";
    long_desc = "The sacred road meets the river street in a churn of broken stone and ash. The junction is desecrated and silent, marked by talon-scores and old bone piles.\n";
    dest_dir = ({
        "domain/original/area/vesla/room211", "west",
        "domain/original/area/vesla/room213", "north",
    });
}
