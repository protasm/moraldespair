inherit "room/room";

void create() {
  ::create();

    short_desc = "Wallside Way";
    long_desc = "The lane hugs the inner wall, its cobbles cracked and uneven beneath drifts of grit. Moss climbs the cold stone blocks, and a broken drainage channel runs dark and still.";
    dest_dir = ({
        "chapter/prologue/area/ruined/room180", "east",
        "chapter/prologue/area/ruined/room182", "west",
    });

  set_light(1);
}

