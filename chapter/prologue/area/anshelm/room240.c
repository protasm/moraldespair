inherit "room/room";

void create() {
  ::create();

  short_desc = "North Street";
  long_desc =
    "The roadway widens here, its center sunk and filled with damp leaves. A fallen\n"
    "signboard lies half-buried in the grit.\n";
  dest_dir = ([
    "south" : "/chapter/prologue/area/anshelm/room239",
    "west" : "/chapter/prologue/area/anshelm/room415",
    "east" : "/chapter/prologue/area/anshelm/room1192",
    "north" : "/chapter/prologue/area/anshelm/room241",
  ]);

  set_light(1);
}
