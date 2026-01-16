inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Entrance to Exedoria";
    long_desc = "Entrance to Exedoria.\n";
    dest_dir = ({
        "domain/original/area/roadway/room27", "west",
        "domain/original/area/exedoria/room286", "city",
    });

  add_exit_alias("c", "city");
}
