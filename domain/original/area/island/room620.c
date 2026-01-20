inherit "room/room";

void create() {
  ::create();


  short_desc = "Island smeltery";
  long_desc = "A heavy chill hangs in the air of this cavernous smeltery, where the\n" +
    "great furnaces once roared. To the west, the street's gray light spills\n" +
    "across a layer of fine ash covering the service counter. A small, soot-\n" +
    "stained sign remains fixed to the stone wall, its lettering faded into\n" +
    "obscurity. To the east, a doorway leads into the shadows of a silent\n" +
    "backroom, stripped of the rhythmic hammers that once defined this space.\n";
  dest_dir = ([
    "east" : "/domain/original/area/island/room621",
    "west" : "/domain/original/area/island/room619",
  ]);

  set_light(1);
}
