inherit "room/room";

void create() {
  ::create();

  short_desc = "South Road";
  long_desc =
    "The old thoroughfare begins in cracked stone and scattered gravel. A line of\n"
    "shutterless facades leans inward, their plaster peeled away.\n";
  dest_dir = ({
    "domain/original/area/anshelm/room1135", "southwest",
    "domain/original/area/anshelm/room236", "south",
    "domain/original/area/anshelm/room1154", "southeast",
    "domain/original/area/anshelm/room238", "north",
  });

  set_light(1);
}
