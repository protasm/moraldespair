inherit "/chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Ruined Works";
  long_desc = "Half-built walls stand around a pit of shattered stone. Tools and braces have\nlong since rotted away.\n";
  dest_dir = ([
    "west":"/chapter/prologue/area/silent/room390",
  ]);

  set_light(1);
}
