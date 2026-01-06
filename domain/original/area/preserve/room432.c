inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Bridge";
    long_desc = "Bridge.\n";
    dest_dir = ({
        "domain/original/area/preserve/room433", "west",
        "domain/original/area/vesla/portal", "vesla",
    });
}
