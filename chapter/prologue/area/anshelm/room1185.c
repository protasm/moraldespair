inherit "room/room";

void create() {
  ::create();

  short_desc = "Broad Street";
  long_desc =
    "A wide street runs beneath faded facades with ornate iron balconies. Many of\n"
    "the balconies have collapsed, leaving jagged anchors.\n";
  dest_dir = ({
    "chapter/prologue/area/anshelm/room239", "west",
    "chapter/prologue/area/anshelm/room1186", "east",
    "chapter/prologue/area/anshelm/room1191", "north",
  });

  set_light(1);
}
