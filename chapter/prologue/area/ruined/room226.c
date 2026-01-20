inherit "room/room";

void create() {
  ::create();

    short_desc = "Desolate Park";
    long_desc = "Stone paths fracture beneath a mat of low weeds and windblown soil. A dry fountain bowl sits cracked and empty under leaning trees.";
    dest_dir = ([
      "south":"/chapter/prologue/area/ruined/room117",
      "west":"/chapter/prologue/area/ruined/room227",
      "east":"/chapter/prologue/area/ruined/room172",
      "north":"/chapter/prologue/area/ruined/room232",
    ]);

  set_light(1);
}
