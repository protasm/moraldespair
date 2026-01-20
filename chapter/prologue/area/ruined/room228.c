inherit "room/room";

void reset(int arg) {
  if (arg)
      return;

  set_light(1);
  short_desc = "Quiet Park";
  long_desc = "A wide clearing lies mute, its stones scattered and moss-dark. Birdless branches arch over the space, their shadows unmoving.";

  dest_dir = ({
    "chapter/prologue/area/ruined/sanctuary", "north",
    "chapter/prologue/area/ruined/room227",   "south",
    "chapter/prologue/area/ruined/room232",   "east",
    "chapter/prologue/area/ruined/room231",   "west",
  });
}
