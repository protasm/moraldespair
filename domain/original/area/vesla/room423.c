inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Glassblower";
    long_desc = "Glassblower\n";
    dest_dir = ({
        "domain/original/area/vesla/room155", "east",
    });
}
