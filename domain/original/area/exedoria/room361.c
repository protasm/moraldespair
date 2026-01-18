inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Heavy Door";
  long_desc = "A massive door hangs from one hinge, leaving a gap into the dark. Rust and rot\nhave eaten the frame.\n";
  dest_dir = ({
    "domain/original/area/exedoria/room356", "east",
  });
}
