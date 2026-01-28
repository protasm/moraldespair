inherit "//chapter/prologue/std/room";

void create() {
  ::create();


  short_desc = "Silver Street";
  long_desc = 
    "A sterile, white radiance bathes this section of the street, emanating\n" +
    "from metallic torches that hum with ancient power. To the west, the\n" +
    "imposing facade of a temple-like structure bears a weathered sign: 'The\n" +
    "Hall of Mazarbul'. An iron fence to the east cordons off a vacant, dust-\n" +
    "choked lot. The pale road continues its path north and south, cutting\n" +
    "a clean line through the silent, surrounding ruins.\n";
  dest_dir = ([
    "west" : "/chapter/prologue/area/island/room690",
    "south" : "/chapter/prologue/area/island/room616",
    "north" : "/chapter/prologue/area/island/room618",
  ]);

  set_light(1);
}
