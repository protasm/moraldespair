inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Rust Racks";
  long_desc = "Empty racks line the walls, their iron pegs eaten with rust and rot. A counter has collapsed under dust-caked scraps, and the floor is littered with blunted fragments that hint at trade long ended.";
  dest_dir = ({
    "domain/original/area/vesla/room230", "east",
    "domain/original/area/vesla/room814", "north",
  });
}
