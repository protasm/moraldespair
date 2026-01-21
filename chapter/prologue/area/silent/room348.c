inherit "room/room";

void create() {
  ::create();

  short_desc = "Cold Hall";
  long_desc = "A narrow hall carries the breath of cold stone. The floor is slick with old\nmoisture.\n";
  dest_dir = ([
    "east":"/chapter/prologue/area/silent/room346",
    "south":"/chapter/prologue/area/silent/room349",
  ]);

  set_light(1);
}
