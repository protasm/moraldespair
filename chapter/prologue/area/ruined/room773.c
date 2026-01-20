inherit "room/room";

void create() {
  ::create();

    short_desc = "Iron Rings";
    long_desc = "Rusty ring bolts stud the posts, and the plank walls bow with age. Old straw dust clings to the floor, mixed with a sour, damp rot.";
    dest_dir = ({
        "chapter/prologue/area/ruined/room789", "south",
        "chapter/prologue/area/ruined/room770", "west",
        "chapter/prologue/area/ruined/room774", "east",
        "chapter/prologue/area/ruined/room788", "north",
    });

  set_light(1);
}

