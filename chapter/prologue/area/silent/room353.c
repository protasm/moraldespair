inherit "room/room";

void create() {
  ::create();

  short_desc = "Cold Kitchen";
  long_desc = "A long hearth sits cold beneath a soot-dark hood. Cracked tables and empty\nshelves crowd the room.\n";
  dest_dir = ({
    "chapter/prologue/area/silent/room352", "south",
  });

  set_light(1);
}
