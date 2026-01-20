inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "West River Track";
    long_desc = "Here the stones are stained dark, as if by old floods that never returned. A toppled iron post lies in the gutter, rusted through.";
    dest_dir = ({
        "chapter/prologue/area/ruined/room151", "east",
        "chapter/prologue/area/ruined/room149", "west",
    });
}
