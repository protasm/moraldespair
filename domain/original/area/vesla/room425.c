inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Omar's Oils II";
    long_desc = "Omar's Oils II\n";
    dest_dir = ({
        "domain/original/area/vesla/room121", "south",
    });
}
