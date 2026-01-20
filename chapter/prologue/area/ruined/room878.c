inherit "room/room";

void create() {
  ::create();

  short_desc = "Empty Stall";
  long_desc = "The vacant room is quiet, its plaster flaking and the air damp. Rotten joists and old fittings hint at a stall once meant for lease.";
  dest_dir = ([
    "south":"/chapter/prologue/area/ruined/room127",
  ]);

  set_light(1);
}
