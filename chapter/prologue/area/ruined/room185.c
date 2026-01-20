inherit "room/room";

void create() {
  ::create();

    short_desc = "Silent Way";
    long_desc = "The lane runs east and west between silent foundations, their doorways collapsed into piles of brick and slate. A brittle vine clings to the mortar seams.";
    dest_dir = ([
      "east":"/chapter/prologue/area/ruined/room178",
      "west":"/chapter/prologue/area/ruined/room186",
    ]);

  set_light(1);
}

