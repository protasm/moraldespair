inherit "/room/room";

void create() {
  ::create();

  short_desc = "Stone Lane";
  long_desc =
    "A straight lane runs east and west through close-set houses. The walls show\n"
    "traces of pale paint and old murals.\n";
  dest_dir = ([
    "east" : "/chapter/prologue/area/refuge/room260",
    "west" : "/chapter/prologue/area/refuge/room262",
  ]);

  set_light(1);
}
