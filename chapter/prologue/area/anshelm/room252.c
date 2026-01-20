inherit "room/room";

void create() {
  ::create();

  short_desc = "Pale Road";
  long_desc =
    "The paving here is pale and smoothed by time. A cracked column base lies\n"
    "beside a doorway.\n";
  dest_dir = ({
    "chapter/prologue/area/anshelm/room251", "south",
    "chapter/prologue/area/anshelm/room253", "north",
  });

  set_light(1);
}
