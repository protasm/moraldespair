inherit "room/room";

void create() {
  ::create();

  short_desc = "Quiet Street";
  long_desc =
    "A narrow street of pale stone stretches between blank walls. Rusted iron\n"
    "brackets jut where balconies once hung.\n";
  dest_dir = ({
    "chapter/prologue/area/anshelm/room413", "west",
    "chapter/prologue/area/anshelm/room237", "south",
    "chapter/prologue/area/anshelm/room239", "north",
  });

  set_light(1);
}
