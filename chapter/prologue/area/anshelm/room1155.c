inherit "room/room";

void create() {
  ::create();

  short_desc = "Side Room";
  long_desc =
    "A side chamber sits empty except for scattered rubble. The plaster has peeled\n"
    "away in long, curling strips.\n";
  dest_dir = ([
    "up" : "/chapter/prologue/area/anshelm/room1158",
    "down" : "/chapter/prologue/area/anshelm/room1156",
    "west" : "/chapter/prologue/area/anshelm/room1154",
  ]);

  set_light(1);
}
