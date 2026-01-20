inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Cold Kitchen";
  long_desc = "A long hearth sits cold beneath a soot-dark hood. Cracked tables and empty\nshelves crowd the room.\n";
  dest_dir = ({
    "chapter/prologue/area/silent/room352", "south",
  });
}
