inherit "//chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Vine Gate";
  long_desc = "Vines curtain a low arch, their roots wedged into the stone. The entry beyond\nis dim and cool.\n";
  dest_dir = ([
    "southwest":"/chapter/prologue/area/silent/room910",
    "southeast":"/chapter/prologue/area/silent/room907",
    "north":"/chapter/prologue/area/silent/room909",
  ]);

  set_light(1);
}
