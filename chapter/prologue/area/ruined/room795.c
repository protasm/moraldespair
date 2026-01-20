inherit "room/room";

void create() {
  ::create();

  short_desc = "Narrow Cut";
  long_desc = "The alley narrows between damp walls, with soot and slime streaking the stone. Old drainage grooves and a collapsed plank hint at service traffic that no longer comes.";
  dest_dir = ({
    "chapter/prologue/area/ruined/room813", "south",
    "chapter/prologue/area/ruined/room792", "west",
    "chapter/prologue/area/ruined/room796", "east",
    "chapter/prologue/area/ruined/room797", "north",
  });

  set_light(1);
}
