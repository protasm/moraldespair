inherit "room/room";

void create() {
  ::create();

  short_desc = "Vine Gate";
  long_desc = "Vines curtain a low arch, their roots wedged into the stone. The entry beyond\nis dim and cool.\n";
  dest_dir = ({
    "chapter/prologue/area/silent/room910", "southwest",
    "chapter/prologue/area/silent/room907", "southeast",
    "chapter/prologue/area/silent/room909", "north",
  });

  set_light(1);
}
