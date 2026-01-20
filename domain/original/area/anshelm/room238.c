inherit "room/room";

void create() {
  ::create();

  short_desc = "Quiet Street";
  long_desc =
    "A narrow street of pale stone stretches between blank walls. Rusted iron\n"
    "brackets jut where balconies once hung.\n";
  dest_dir = ({
    "domain/original/area/anshelm/room413", "west",
    "domain/original/area/anshelm/room237", "south",
    "domain/original/area/anshelm/room239", "north",
  });

  set_light(1);
}
