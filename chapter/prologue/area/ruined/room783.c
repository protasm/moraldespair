inherit "room/room";

void create() {
  ::create();

    short_desc = "Saddle Racks";
    long_desc = "Bare racks line one side, warped and splintered by time. Rust flakes from old fittings, and dust gathers in soft drifts.";
    dest_dir = ({
        "chapter/prologue/area/ruined/room778", "northeast",
        "chapter/prologue/area/ruined/room779", "east",
        "chapter/prologue/area/ruined/room777", "north",
    });

  set_light(1);
}

