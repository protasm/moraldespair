inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "West Steps";
  long_desc =
    "Broad steps descend through the gatehouse, cracked and uneven. A strip of\n"
    "faded tile clings to the wall.\n";
  dest_dir = ({
    "domain/original/area/anshelm/room1137", "up",
  });
}
