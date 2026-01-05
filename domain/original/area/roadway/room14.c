inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Near Vesla City";
    long_desc = "Near Vesla City.\n";
    dest_dir = ({
        "domain/original/area/roadway/room13", "west",
	"domain/original/area/vesla/room115", "city",
    });
}
