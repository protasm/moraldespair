inherit "room/room";

void reset(int arg) {
  if (arg)
    return;

  set_light(1);

  short_desc = "Dull Chime";
  long_desc = "Broken molds and a rusted frame lie in silent dust, the shop in ruin. Rot and\n"
        + "mildew stain the stone, hinting at chimes once shaped here in neglect.\n";
  dest_dir = ({
    "domain/original/area/vesla/room214", "east",
  });
}
