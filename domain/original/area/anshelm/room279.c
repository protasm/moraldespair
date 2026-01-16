inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Quiet Way";
  long_desc =
    "The stone is cracked and uneven, with weeds in the seams. A line of iron pegs\n"
    "runs along one wall.\n";
  dest_dir = ({
    "domain/original/area/anshelm/room280", "east",
    "domain/original/area/anshelm/room278", "west",
  });
}
