inherit "//chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Quiet Park";
  long_desc = "A wide clearing lies mute, its stones scattered and moss-dark. Birdless branches arch over the space, their shadows unmoving.";
  dest_dir = ([
    "north":"/chapter/prologue/area/ruined/room/sanctuary",
    "south":"/chapter/prologue/area/ruined/room/room227",
    "east":"/chapter/prologue/area/ruined/room/room232",
    "west":"/chapter/prologue/area/ruined/room/room231",
  ]);

}
