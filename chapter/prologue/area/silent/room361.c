inherit "room/room";

void create() {
  ::create();

  short_desc = "Heavy Door";
  long_desc = "A massive door hangs from one hinge, leaving a gap into the dark. Rust and rot\nhave eaten the frame.\n";
  dest_dir = ({
    "chapter/prologue/area/silent/room356", "east",
  });

  set_light(1);
}
