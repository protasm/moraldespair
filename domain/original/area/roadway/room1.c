inherit "room/room";

void reset(int arg) {
    if (arg) return;

    set_light(1);

    short_desc = "Entrance to Candera";
    long_desc = "Entrance to Candera.\n";
    dest_dir = ({
        "domain/original/area/roadway/room2", "east",
	"domain/original/area/candera/room1", "city",
    });

    add_exit_alias("c", "city");
}
