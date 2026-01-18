inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Ruined Works";
  long_desc = "Half-built walls stand around a pit of shattered stone. Tools and braces have\nlong since rotted away.\n";
  dest_dir = ({
    "domain/original/area/exedoria/room390", "west",
  });
}
