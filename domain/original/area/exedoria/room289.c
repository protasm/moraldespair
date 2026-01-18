inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Rutted Street";
  long_desc = "Loose gravel and dirt bury the street's edge. Low foundations crouch in the\nweeds, their doorways open to the air.\n";
  dest_dir = ({
    "domain/original/area/exedoria/room288", "west",
    "domain/original/area/exedoria/room290", "east",
    "domain/original/area/exedoria/room366", "south",
  });
}
