inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Faded Chamber";
  long_desc = "Pale plaster peels from the walls, revealing dark stains of damp and rot. A small table has split in two, and a stub of candle wax sits in dust where soft music once played.";
  dest_dir = ({
    "domain/original/area/vesla/room825", "south",
  });
}
