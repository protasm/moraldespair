inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Smithy";
    long_desc = "Smithy";
    dest_dir = ({
        "domain/original/area/vesla/room160", "west",
        "domain/original/area/vesla/room124", "south",
    });
}
