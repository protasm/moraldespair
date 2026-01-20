inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Cracked Circle";
  long_desc = "A low ring of stone marks a circle at the center of the road. Whatever stood\nhere is gone, leaving only shattered plinths.\n";
  dest_dir = ({
    "chapter/prologue/area/silent/room299", "south",
    "chapter/prologue/area/silent/room289", "west",
    "chapter/prologue/area/silent/room291", "east",
    "chapter/prologue/area/silent/room369", "north",
  });
}
