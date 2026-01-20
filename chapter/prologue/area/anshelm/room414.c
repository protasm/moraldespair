inherit "room/room";

void create() {
  ::create();

  short_desc = "Lamp Street";
  long_desc =
    "The street bends past a row of battered lamp posts and narrow doors. Faded\n"
    "plaster still carries traces of painted vines.\n";
  dest_dir = ({
    "chapter/prologue/area/anshelm/room413", "south",
    "chapter/prologue/area/anshelm/room1147", "west",
    "chapter/prologue/area/anshelm/room239", "east",
    "chapter/prologue/area/anshelm/room415", "north",
  });

  set_light(1);
}
