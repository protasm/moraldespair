inherit "room/room";

void create() {
  ::create();

  short_desc = "Old Armoury";
  long_desc = "Empty racks line the walls, their pegs snapped off. A few rusted scraps lie in\nthe corners.\n";
  dest_dir = ({
    "chapter/prologue/area/silent/room920", "west",
  });

  set_light(1);
}
