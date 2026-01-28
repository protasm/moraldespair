inherit "/chapter/prologue/std/room";

void create() {
  ::create();


  short_desc = "A narrow path between the dunes";
  long_desc = "High, shifting mounds of sand wall in this narrow corridor. To the north,\n" +
    "two salt-pitted stone pillars stand like skeletal sentinels marking a\n" +
    "forgotten threshold. The path leads south toward the sound of the surf\n" +
    "and north toward the looming city silhouette.\n";
  dest_dir = ([
    "south" : "/chapter/prologue/area/island/room606",
    "east" : "/chapter/prologue/area/island/room628",
    "north" : "/chapter/prologue/area/island/room608",
  ]);

  set_light(1);
}
