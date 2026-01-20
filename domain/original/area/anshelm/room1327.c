inherit "room/room";

void create() {
  ::create();

  short_desc = "Ruined Stables";
  long_desc =
    "Low stalls line the walls, their timber slats collapsed and gray. A trough\n"
    "sits dry beneath a broken window.\n";
  dest_dir = ({
    "domain/original/area/anshelm/room284", "south",
  });

  set_light(1);
}
