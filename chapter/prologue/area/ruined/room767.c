inherit "room/room";

void create() {
  ::create();

  short_desc = "Echo Court";
  long_desc = "The court here is narrower, hemmed by rough walls and roofless alcoves. A rusted bracket and a shallow socket in the stone hint at a former lantern line.";
  dest_dir = ({
    "chapter/prologue/area/ruined/room768", "east",
    "chapter/prologue/area/ruined/room765", "southeast",
    "chapter/prologue/area/ruined/room766", "south",
  });

  set_light(1);
}
