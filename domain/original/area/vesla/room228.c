inherit "room/room";

void reset(int arg) {
  if (arg)
      return;

  set_light(1);
  short_desc = "Quiet Park";
  long_desc = "A wide clearing lies mute, its stones scattered and moss-dark. Birdless branches arch over the space, their shadows unmoving.";

  dest_dir = ({
    "domain/original/area/vesla/sanctuary", "north",
    "domain/original/area/vesla/room227",   "south",
    "domain/original/area/vesla/room232",   "east",
    "domain/original/area/vesla/room231",   "west",
  });
}
