inherit "room/room";

void create() {
  ::create();

  short_desc = "North Street";
  long_desc =
    "The roadway widens here, its center sunk and filled with damp leaves. A fallen\n"
    "signboard lies half-buried in the grit.\n";
  dest_dir = ({
    "domain/original/area/anshelm/room239", "south",
    "domain/original/area/anshelm/room415", "west",
    "domain/original/area/anshelm/room1192", "east",
    "domain/original/area/anshelm/room241", "north",
  });

  set_light(1);
}
