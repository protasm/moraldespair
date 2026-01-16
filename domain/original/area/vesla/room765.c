inherit "room/room";

void reset(int arg) {
  if (arg)
    return;

  set_light(1);

  short_desc = "Ruined Court";
  long_desc = "The court widens toward a collapsed corner, its paving buckled and\n"
    "wet with seepage. A half-ruined post and iron ring suggest where\n"
    "orders and notices once hung.\n";
  dest_dir = ({
    "domain/original/area/vesla/room766", "west",
    "domain/original/area/vesla/room767", "northwest",
    "domain/original/area/vesla/room758", "south",
    "domain/original/area/vesla/room757", "southwest",
    "domain/original/area/vesla/room769", "northeast",
    "domain/original/area/vesla/room770", "east",
    "domain/original/area/vesla/room768", "north",
  });
}
