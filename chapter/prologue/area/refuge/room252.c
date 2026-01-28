inherit "/chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Pale Road";
  long_desc =
    "The paving here is pale and smoothed by time. A cracked column base lies\n"
    "beside a doorway.\n";
  dest_dir = ([
    "south" : "/chapter/prologue/area/refuge/room251",
    "north" : "/chapter/prologue/area/refuge/room253",
  ]);

  set_light(1);
}
