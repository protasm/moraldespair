inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "West River Road";
    long_desc = "Here the stones are stained dark, as if by old floods\n"
                + "that never returned.\n"
                + "A toppled iron post lies in the gutter, rusted through.\n";
    dest_dir = ({
        "domain/original/area/vesla/room151", "east",
        "domain/original/area/vesla/room149", "west",
    });
}
