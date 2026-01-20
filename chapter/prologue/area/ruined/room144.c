inherit "room/room";

void create() {
  ::create();

    short_desc = "West River Track";
    long_desc = "The westward river road is split by frost and root, the stones heaved uneven. A dry gutter runs alongside, packed with silt and curled leaves.";
    dest_dir = ([
      "west":"/chapter/prologue/area/ruined/room143",
      "east":"/chapter/prologue/area/ruined/room145",
      "south":"/chapter/prologue/area/ruined/room847",
    ]);

  set_light(1);
}
