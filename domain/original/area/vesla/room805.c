inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Sour Shed";
  long_desc = "The shed reeks of damp earth and rot, with sacks collapsed into dark pulp. A battered scoop and stained planks hint at soil and dung once bartered here.";
  dest_dir = ({
    "domain/original/area/vesla/room802", "north",
  });
}
