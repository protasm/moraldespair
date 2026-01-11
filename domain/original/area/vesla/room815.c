inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Rust Racks";
  long_desc = "Empty racks line the walls, their iron pegs eaten with rust and rot. A counter\n"
              + "has collapsed under dust-caked scraps, and the floor is littered with blunted\n"
              + "fragments that hint at trade long ended.\n";
  dest_dir = ({
    "domain/original/area/vesla/room230", "east",
    "domain/original/area/vesla/room814", "north",
  });
}
