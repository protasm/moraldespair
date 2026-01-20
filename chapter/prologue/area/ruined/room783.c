inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Saddle Racks";
    long_desc = "Bare racks line one side, warped and splintered by time. Rust flakes from old fittings, and dust gathers in soft drifts.";
    dest_dir = ({
        "chapter/prologue/area/ruined/room778", "northeast",
        "chapter/prologue/area/ruined/room779", "east",
        "chapter/prologue/area/ruined/room777", "north",
    });
}

