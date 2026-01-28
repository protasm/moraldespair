inherit "/chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Narrow Lane";
  long_desc =
    "The lane pinches between tall, close walls of mottled stone. A ribbon of ivy\n"
    "trails down from a broken cornice.\n";
  dest_dir = ([
    "east" : "/chapter/prologue/area/refuge/room244",
    "west" : "/chapter/prologue/area/refuge/room246",
  ]);

  set_light(1);
}
