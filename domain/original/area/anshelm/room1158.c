inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Inner Stair";
  long_desc =
    "A stone stair rises along a battered wall, its steps chipped and damp. A\n"
    "broken lantern hook hangs above the landing.\n";
  dest_dir = ({
    "domain/original/area/anshelm/room1155", "down",
    "domain/original/area/anshelm/room1159", "up",
  });
}
