inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Rutted Street";
  long_desc = "Loose gravel and dirt bury the street's edge. Low foundations crouch in the\nweeds, their doorways open to the air.\n";
  dest_dir = ({
    "chapter/prologue/area/silent/room288", "west",
    "chapter/prologue/area/silent/room290", "east",
    "chapter/prologue/area/silent/room366", "south",
  });
}
