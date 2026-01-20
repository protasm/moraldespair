inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Cold Hall";
  long_desc = "A narrow hall carries the breath of cold stone. The floor is slick with old\nmoisture.\n";
  dest_dir = ({
    "chapter/prologue/area/silent/room346", "east",
    "chapter/prologue/area/silent/room349", "south",
  });
}
