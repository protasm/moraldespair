inherit "room/room";

void reset(int arg) {
  if (arg)
    return;

  set_light(1);

  short_desc = "Stone Trough";
  long_desc = "A shallow trough sits in a drained corner, its stones green with\n"
    "mildew and grit. Cracked channels run toward a blocked grate,\n"
    "suggesting long-abandoned care for animals.\n";
  dest_dir = ({
    "domain/original/area/vesla/room778", "southeast",
    "domain/original/area/vesla/room777", "south",
  });
}
