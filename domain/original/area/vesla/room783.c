inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Saddle Racks";
    long_desc = "Bare racks line one side, warped and splintered by time. Rust flakes\n"
                + "from old fittings, and dust gathers in soft drifts.\n";
    dest_dir = ({
        "domain/original/area/vesla/room778", "northeast",
        "domain/original/area/vesla/room779", "east",
        "domain/original/area/vesla/room777", "north",
    });
}

