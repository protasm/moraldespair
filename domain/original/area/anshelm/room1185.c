inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Broad Street";
  long_desc =
    "A wide street runs beneath faded facades with ornate iron balconies. Many of\n"
    "the balconies have collapsed, leaving jagged anchors.\n";
  dest_dir = ({
    "domain/original/area/anshelm/room239", "west",
    "domain/original/area/anshelm/room1186", "east",
    "domain/original/area/anshelm/room1191", "north",
  });
}
