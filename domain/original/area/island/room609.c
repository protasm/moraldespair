inherit "room/room";

void create() {
  ::create();


  short_desc = "The City Gate";
  long_desc = "Two monolithic pillars rise into the stagnant sky, their stone faces\n" +
    "pitted by centuries of salt and wind. Hollow cavities, once serving as\n" +
    "watch-posts, stare like empty eye sockets to the east and west. Faded\n" +
    "runes are carved deep into the rock, though only the word 'Welcome'\n" +
    "remains legible. To the north, a brick-paved street stretches between\n" +
    "rows of cold, metallic torches.\n";
  dest_dir = ({
    "domain/original/area/island/room608", "south",
    "domain/original/area/island/room631", "west",
    "domain/original/area/island/room634", "east",
    "domain/original/area/island/room610", "north",
  });

  set_light(1);
}
