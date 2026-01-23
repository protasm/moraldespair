inherit "room/room";

void create() {
  ::create();

  short_desc = "Iron Walk";
  long_desc =
    "Old iron rails bracket the street, many bent or missing. The roadway is\n"
    "scarred by shallow ruts.\n";
  dest_dir = ([
    "south" : "/chapter/prologue/area/refuge/room253",
    "north" : "/chapter/prologue/area/refuge/room255",
  ]);

  set_light(1);
}
