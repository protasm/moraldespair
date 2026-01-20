inherit "room/room";

void create() {
  ::create();

  short_desc = "Silent Hall";
  long_desc =
    "Long tables are gone, but their scars remain in the floor. A hearth stands\n"
    "cold beneath a chipped mantle.\n";
  dest_dir = ({
    "domain/original/area/anshelm/room1145", "east",
    "domain/original/area/anshelm/room1138", "west",
  });

  set_light(1);
}
