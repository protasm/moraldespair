inherit "/chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "South Road";
  long_desc =
    "The old thoroughfare begins in cracked stone and scattered gravel. A line of\n"
    "shutterless facades leans inward, their plaster peeled away.\n";
  dest_dir = ([
    "southwest" : "/chapter/prologue/area/refuge/room1135",
    "south" : "/chapter/prologue/area/refuge/room236",
    "southeast" : "/chapter/prologue/area/refuge/room1154",
    "north" : "/chapter/prologue/area/refuge/room238",
  ]);

  set_light(1);
}
