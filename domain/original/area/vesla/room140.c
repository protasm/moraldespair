inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Somber Junction";
  long_desc = "A wider crossing opens where the paving is deeply scored by cart ruts and rain. The basalt is cracked into plates, and iron rings lie rusted into the stones.";
  dest_dir = ({
    "domain/original/area/vesla/room141", "south",
    "domain/original/area/vesla/room204", "east",
    "domain/original/area/vesla/room139", "north",
  });
}

