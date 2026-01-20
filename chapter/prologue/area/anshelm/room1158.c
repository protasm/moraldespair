inherit "room/room";

void create() {
  ::create();

  short_desc = "Inner Stair";
  long_desc =
    "A stone stair rises along a battered wall, its steps chipped and damp. A\n"
    "broken lantern hook hangs above the landing.\n";
  dest_dir = ({
    "chapter/prologue/area/anshelm/room1155", "down",
    "chapter/prologue/area/anshelm/room1159", "up",
  });

  set_light(1);
}
