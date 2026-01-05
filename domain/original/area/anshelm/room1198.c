inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "You have to turn sideways a bit to squeeze through the narrow passage.";
    long_desc = "You have to turn sideways a bit to squeeze through the narrow passage.\n";
    dest_dir = ({
        "domain/original/area/anshelm/room265", "west",
    });
}
