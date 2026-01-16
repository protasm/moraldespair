inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Near Vesla City";
    long_desc = "Near Vesla City.\n";
    dest_dir = ({
        "domain/original/area/roadway/room30", "north",
        "domain/original/area/roadway/room43", "south",
        "domain/original/area/roadway/room13", "west",
        "domain/original/area/roadway/room16", "east",
	"domain/original/area/vesla/room115", "city",
    });

  add_exit_alias("c", "city");
}
