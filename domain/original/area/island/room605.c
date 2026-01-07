inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Ocean before Beachhead";
    long_desc = "Ocean before Beachhead.\n";
    dest_dir = ({
        "domain/original/area/island/room606", "north",
	"domain/original/area/vesla/portal", "vesla",
    });
}
