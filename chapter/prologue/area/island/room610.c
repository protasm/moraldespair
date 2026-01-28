inherit "/chapter/prologue/std/room";

void create() {
  ::create();


  short_desc = "Intersection of Silver Street and Balin Road";
  long_desc = "Polished stone meets weathered brick at this silent junction. To the\n" +
    "north, the pale length of Silver Street stretches toward the hollow\n" +
    "shells of distant temples. Four massive metallic torches stand at the\n" +
    "corners, their frames blackened and cold. The bustling crowds are long\n" +
    "gone, leaving only the wind to whistle through the empty thoroughfares.\n";
  dest_dir = ([
    "south" : "/chapter/prologue/area/island/room609",
    "west" : "/chapter/prologue/area/island/room635",
    "east" : "/chapter/prologue/area/island/room660",
    "north" : "/chapter/prologue/area/island/room611",
  ]);

  set_light(1);
}
