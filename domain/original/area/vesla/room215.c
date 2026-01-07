inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Desecrated Via Sacra";
    long_desc = "Charred pillars and shattered altars line the once-holy way. The stones are cracked and cold, abandoned for two centuries.\n";
    dest_dir = ({
        "domain/original/area/vesla/room214", "south",
        "domain/original/area/vesla/room216", "north",
    });
}
