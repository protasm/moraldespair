inherit "room/room";

void create() {
  ::create();

  short_desc = "Old Armory";
  long_desc =
    "A stout stone building squats behind a collapsed lintel. Rusted hooks and\n"
    "empty racks line the interior walls.\n";
  dest_dir = ({
    "chapter/prologue/area/anshelm/room246", "north",
  });

  set_light(1);
}
