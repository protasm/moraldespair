inherit "room/room";

void create() {
  ::create();

  short_desc = "Rust Racks";
  long_desc = "Empty racks line the walls, their iron pegs eaten with rust and rot. A counter has collapsed under dust-caked scraps, and the floor is littered with blunted fragments that hint at trade long ended.";
  dest_dir = ([
    "east":"/chapter/prologue/area/ruined/room230",
    "north":"/chapter/prologue/area/ruined/room814",
  ]);

  set_light(1);
}
