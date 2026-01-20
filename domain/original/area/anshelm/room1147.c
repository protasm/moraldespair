inherit "room/room";

void create() {
  ::create();

  short_desc = "Promenade";
  long_desc =
    "A broad walk runs along the inner wall, its stone railing cracked and low.\n"
    "Ornate ironwork curves still cling to a few posts.\n";
  dest_dir = ({
    "domain/original/area/anshelm/room1150", "west",
    "domain/original/area/anshelm/room414", "east",
    "domain/original/area/anshelm/room1169", "north",
  });

  set_light(1);
}
