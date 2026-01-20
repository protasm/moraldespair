inherit "room/room";

void create() {
  ::create();


  short_desc = "A Grand Plaza";
  long_desc =  "Intricate brickwork spreads across this vast expanse, forming faded\n" +
    "crests and silver crosses that bleed into the surrounding stone. In the\n" +
    "center, a gnarled tree erupts from a raised circular dais, its roots\n" +
    "cracking the masonry in a slow, silent conquest. A forest of metallic\n" +
    "torches stands frozen around the perimeter, their glass housings clouded\n" +
    "by time. To the north, the path climbs toward a high, shadowed hill.\n";
  dest_dir = ({
    "domain/original/area/island/room613", "south",
    "domain/original/area/island/room678", "west",
    "domain/original/area/island/room677", "east",
    "domain/original/area/island/room615", "north",
  });

  set_light(1);
}
