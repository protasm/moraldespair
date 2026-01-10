inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Buried Wreckage";
    long_desc = "Buried Wreckage";
    dest_dir = ({
        "domain/original/area/vesla/room199", "west",
    });
}
