inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Old Armoury";
  long_desc = "Empty racks line the walls, their pegs snapped off. A few rusted scraps lie in\nthe corners.\n";
  dest_dir = ({
    "domain/original/area/exedoria/room920", "west",
  });
}
