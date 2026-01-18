inherit "room/room";

void reset(int arg) {
  if (arg)
    return;

  set_light(1);

  short_desc = "Rear Rooms";
  long_desc = "A narrow back room lies in silence, its shelves sagging with dust and mildew. Rot has taken the warped counter, hinting at storage and trade long abandoned.";
  dest_dir = ({
    "domain/original/area/vesla/room138", "west",
  });
}
