inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Old Armory";
  long_desc =
    "A stout stone building squats behind a collapsed lintel. Rusted hooks and\n"
    "empty racks line the interior walls.\n";
  dest_dir = ({
    "domain/original/area/anshelm/room246", "north",
  });
}
