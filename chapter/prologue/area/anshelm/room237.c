inherit "room/room";

void create() {
  ::create();

  short_desc = "South Road";
  long_desc =
    "The old thoroughfare begins in cracked stone and scattered gravel. A line of\n"
    "shutterless facades leans inward, their plaster peeled away.\n";
  dest_dir = ([
    "southwest" : "/chapter/prologue/area/anshelm/room1135",
    "south" : "/chapter/prologue/area/anshelm/room236",
    "southeast" : "/chapter/prologue/area/anshelm/room1154",
    "north" : "/chapter/prologue/area/anshelm/room238",
  ]);

  set_light(1);
}
