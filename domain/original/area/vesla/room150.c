inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "West River Track";
    long_desc = "Here the stones are stained dark, as if by old floods that never returned. A toppled iron post lies in the gutter, rusted through.";
    dest_dir = ({
        "domain/original/area/vesla/room151", "east",
        "domain/original/area/vesla/room149", "west",
    });
}
