inherit "room/room";

void create() {
  ::create();

  short_desc = "Quiet Park";
  long_desc = "A wide clearing lies mute, its stones scattered and moss-dark. Birdless branches arch over the space, their shadows unmoving.";
  dest_dir = ([
    "north":"/chapter/prologue/area/ruined/sanctuary",
    "south":"/chapter/prologue/area/ruined/room227",
    "east":"/chapter/prologue/area/ruined/room232",
    "west":"/chapter/prologue/area/ruined/room231",
  ]);

  set_light(1);
}
