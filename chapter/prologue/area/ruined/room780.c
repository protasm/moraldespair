inherit "room/room";

void reset(int arg) {
  if (arg)
    return;

  set_light(1);

  short_desc = "Stone Trough";
  long_desc = "A shallow trough sits in a drained corner, its stones green with mildew and grit. Cracked channels run toward a blocked grate, suggesting long-abandoned care for animals.";
  dest_dir = ({
    "chapter/prologue/area/ruined/room778", "southeast",
    "chapter/prologue/area/ruined/room777", "south",
  });
}
