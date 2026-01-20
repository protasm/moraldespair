inherit "room/room";

void create() {
  ::create();

  short_desc = "Mossed Way";
  long_desc = "Broken curbstones edge a long, silent way, their faces dark with mildew and rain stain. A scatter of toppled posts and empty brackets hints at old markers now swallowed by grit.";
  dest_dir = ({
    "chapter/prologue/area/ruined/room200", "south",
    "chapter/prologue/area/ruined/room962", "east",
    "chapter/prologue/area/ruined/room198", "north",
  });

  set_light(1);
}
