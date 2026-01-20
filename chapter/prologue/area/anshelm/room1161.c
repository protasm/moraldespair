inherit "room/room";

void create() {
  ::create();

  short_desc = "Broken Chamber";
  long_desc =
    "The chamber is broad but empty, with a roof caved in at one end. Charred beams\n"
    "lie across the floor.\n";
  dest_dir = ({
    "chapter/prologue/area/anshelm/room1160", "east",
    "chapter/prologue/area/anshelm/room1162", "west",
  });

  set_light(1);
}
