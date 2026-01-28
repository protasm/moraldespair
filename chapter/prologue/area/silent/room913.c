inherit "//chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Servant Wing";
  long_desc = "Hanging vines trail through a low entry into a row of small rooms. The floor\nis littered with leaves and dust.\n";
  dest_dir = ([
    "west":"/chapter/prologue/area/silent/room912",
  ]);

  set_light(1);
}
