inherit "room/room";

void create() {
  ::create();

  short_desc = "Quiet Parlor";
  long_desc = "This back room is heavy with stale air, its cushions reduced to moldy husks. A low screen has fallen across the floor, and the only scent left is damp wood and dust.";
  dest_dir = ({
    "chapter/prologue/area/ruined/room825", "down",
  });

  set_light(1);
}
