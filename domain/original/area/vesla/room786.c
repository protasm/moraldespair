inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Tack room";
    long_desc = "Tack room";
    dest_dir = ({
        "domain/original/area/vesla/room774", "south",
    });
}
