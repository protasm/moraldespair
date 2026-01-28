inherit "/chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Old Cemetery";
  long_desc = "Graves spread across a low field, their markers tilted and worn. The ground is\nuneven with sunken plots.\n";
  dest_dir = ([
    "west":"/chapter/prologue/area/silent/room926",
  ]);

  set_light(1);
}
