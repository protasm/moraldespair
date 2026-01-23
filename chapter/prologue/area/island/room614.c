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
  dest_dir = ([
    "south" : "/chapter/prologue/area/island/room613",
    "west" : "/chapter/prologue/area/island/room678",
    "east" : "/chapter/prologue/area/island/room677",
    "north" : "/chapter/prologue/area/island/room615",
  ]);

  set_light(1);
}
