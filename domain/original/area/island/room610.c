inherit "room/room";

void create() {
  ::create();


  short_desc = "Intersection of Silver Street and Balin Road";
  long_desc = "Polished stone meets weathered brick at this silent junction. To the\n" +
    "north, the pale length of Silver Street stretches toward the hollow\n" +
    "shells of distant temples. Four massive metallic torches stand at the\n" +
    "corners, their frames blackened and cold. The bustling crowds are long\n" +
    "gone, leaving only the wind to whistle through the empty thoroughfares.\n";
  dest_dir = ({
    "domain/original/area/island/room609", "south",
    "domain/original/area/island/room635", "west",
    "domain/original/area/island/room660", "east",
    "domain/original/area/island/room611", "north",
  });

  set_light(1);
}
