inherit "room/room";

void create() {
  ::create();

    short_desc = "Empty Stalls";
    long_desc = "Stall partitions linger as gray ribs, and rusted hinges hang from them. The floor is packed hard and bare, with only the stink of wet rot left.";
    dest_dir = ({
        "chapter/prologue/area/ruined/room783", "west",
        "chapter/prologue/area/ruined/room777", "northwest",
        "chapter/prologue/area/ruined/room778", "north",
    });

  set_light(1);
}

