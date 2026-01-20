inherit "room/room";

void create() {
  ::create();

  short_desc = "Silent Hearth";
  long_desc = "A wide, cold hearth sits beneath a soot-dark mantle, the room silent and ruined. Rotted tables lean in dust and mildew, and the common space is left to sag.";
  dest_dir = ({
    "chapter/prologue/area/ruined/room142", "west",
    "chapter/prologue/area/ruined/room852", "east",
    "chapter/prologue/area/ruined/room851", "north",
  });

  set_light(1);
}
