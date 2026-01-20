inherit "room/room";

void create() {
  ::create();

    short_desc = "Iron Rings";
    long_desc = "Rusty ring bolts stud the posts, and the plank walls bow with age. Old straw dust clings to the floor, mixed with a sour, damp rot.";
    dest_dir = ([
      "south":"/chapter/prologue/area/ruined/room789",
      "west":"/chapter/prologue/area/ruined/room770",
      "east":"/chapter/prologue/area/ruined/room774",
      "north":"/chapter/prologue/area/ruined/room788",
    ]);

  set_light(1);
}

