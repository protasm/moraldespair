inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Basalt Avenue";
  long_desc = "Basalt blocks crowd the street, their faces chipped and dark with thick soot. Doorways gape into shadow, and the avenue is filmed with fine dust and leaf rot.";
  dest_dir = ({
    "chapter/prologue/area/ruined/room139", "south",
    "chapter/prologue/area/ruined/room856", "west",
    "chapter/prologue/area/ruined/room855", "east",
    "chapter/prologue/area/ruined/room137", "north",
  });
}
