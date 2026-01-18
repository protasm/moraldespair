inherit "room/room";

void reset(int arg) {
  if (arg)
    return;

  set_light(1);

  short_desc = "Narrow Cut";
  long_desc = "The alley narrows between damp walls, with soot and slime streaking the stone. Old drainage grooves and a collapsed plank hint at service traffic that no longer comes.";
  dest_dir = ({
    "domain/original/area/vesla/room813", "south",
    "domain/original/area/vesla/room792", "west",
    "domain/original/area/vesla/room796", "east",
    "domain/original/area/vesla/room797", "north",
  });
}
