inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Quiet Racks";
    long_desc = "Narrow sleeping frames stand in two lines, stripped to bare wood and cobweb. A boarded alcove gapes at the far end, and the boards sag with damp.";
    dest_dir = ({
        "chapter/prologue/area/ruined/room745", "west",
    });
}

