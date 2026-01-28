inherit "/chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Paved Cross";
  long_desc = "A square of broken paving holds the meeting of several paths. The stones are\nsunken and split by roots.\n";
  dest_dir = ([
    "east":"/chapter/prologue/area/silent/room388",
    "northwest":"/chapter/prologue/area/silent/room386",
    "south":"/chapter/prologue/area/silent/room527",
  ]);

  set_light(1);
}
