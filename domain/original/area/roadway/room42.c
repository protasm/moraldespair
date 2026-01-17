inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Defiled City";
    long_desc = "The defiled remains of a final refuge.";
    dest_dir = ({
        "domain/original/area/roadway/room41", "south",
        "domain/original/area/anshelm/room235", "city",
    });

  add_exit_alias("c", "city");
}



