inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "City Graveyard";
    long_desc = "A graveyard where a city once thrived.";
    dest_dir = ({
        "domain/original/area/roadway/room27", "west",
        "domain/original/area/exedoria/room286", "city",
    });

  add_exit_alias("c", "city");
}



