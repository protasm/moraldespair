inherit "room/room";

void create() {
  ::create();

  short_desc = "Rear Rooms";
  long_desc = "A narrow back room lies in silence, its shelves sagging with dust and mildew. Rot has taken the warped counter, hinting at storage and trade long abandoned.";
  dest_dir = ({
    "chapter/prologue/area/ruined/room138", "west",
  });

  set_light(1);
}
