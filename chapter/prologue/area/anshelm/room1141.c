inherit "room/room";

void create() {
  ::create();

  short_desc = "West Steps";
  long_desc =
    "Broad steps descend through the gatehouse, cracked and uneven. A strip of\n"
    "faded tile clings to the wall.\n";
  dest_dir = ({
    "chapter/prologue/area/anshelm/room1137", "up",
  });

  set_light(1);
}
