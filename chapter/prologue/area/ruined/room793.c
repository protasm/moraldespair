inherit "room/room";

void create() {
  ::create();

    short_desc = "Overgrown Beds";
    long_desc = "Overgrown beds sag beneath nettles and mildew-dark leaves, their borders crumbled. A fallen trellis and a cracked basin suggest careful tending long since undone.";
    dest_dir = ({
        "chapter/prologue/area/ruined/room168", "east",
    });

  set_light(1);
}

