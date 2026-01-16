inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Cold Kitchen";
  long_desc = "A long hearth sits cold beneath a soot-dark hood. Cracked tables and empty\nshelves crowd the room.\n";
  dest_dir = ({
    "domain/original/area/exedoria/room352", "south",
  });
}
