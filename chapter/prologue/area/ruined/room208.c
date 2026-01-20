inherit "room/room";

void create() {
  ::create();

    short_desc = "East River Track";
    long_desc = "The road narrows between blank fronts, their doors hanging askew. Wind has swept the stones clean in thin streaks.";
    dest_dir = ({
        "chapter/prologue/area/ruined/room207", "west",
        "chapter/prologue/area/ruined/room209", "east",
        "chapter/prologue/area/ruined/room396", "north",
    });

  set_light(1);
}
