inherit "room/room";

void create() {
  ::create();

  short_desc = "Stale Cut";
  long_desc = "The dead-end passage is choked with grit and damp cobbles, quiet under sagging walls. Faint nail holes in the stone imply shelving or a lean-to long since gone.";
  dest_dir = ({
    "chapter/prologue/area/ruined/room800", "west",
  });

  set_light(1);
}
