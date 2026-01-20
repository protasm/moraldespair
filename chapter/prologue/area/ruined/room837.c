inherit "room/room";

void create() {
  ::create();

  short_desc = "Stalled Row";
  long_desc = "Rotted awnings sag over empty stalls, their poles splintered and gray. Scales and shallow trays lie scattered in dust, and mildew darkens the stone where trade once clustered.";
  dest_dir = ({
    "chapter/prologue/area/ruined/room422", "west",
  });

  set_light(1);
}
