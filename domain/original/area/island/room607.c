inherit "room/room";

void create() {
  ::create();


  short_desc = "A narrow path between the dunes";
  long_desc = "High, shifting mounds of sand wall in this narrow corridor. To the north,\n" +
    "two salt-pitted stone pillars stand like skeletal sentinels marking a\n" +
    "forgotten threshold. The path leads south toward the sound of the surf\n" +
    "and north toward the looming city silhouette.\n";
  dest_dir = ([
    "south" : "/domain/original/area/island/room606",
    "east" : "/domain/original/area/island/room628",
    "north" : "/domain/original/area/island/room608",
  ]);

  set_light(1);
}
