inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Private Entry";
    long_desc = "Private Entry.\n";
    dest_dir = ({
        "domain/original/area/anshelm/room281", "south",
    });
}
