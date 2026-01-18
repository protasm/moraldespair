inherit "room/room";

void reset(int arg) {
  if (arg)
    return;

  set_light(1);

  short_desc = "Dull Chime";
  long_desc = "Broken molds and a rusted frame lie in silent dust, the shop in ruin. Rot and mildew stain the stone, hinting at chimes once shaped here in neglect.";
  dest_dir = ({
    "domain/original/area/vesla/room214", "east",
  });
}
