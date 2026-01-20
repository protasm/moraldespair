inherit "room/room";

void create() {
  ::create();

    short_desc = "Split Rails";
    long_desc = "Split rails mark the stall lines, some fallen flat into the dirt. The ground is rutted and cold, with a sour odor of rot.";
    dest_dir = ([
      "north":"/chapter/prologue/area/ruined/room775",
    ]);

  set_light(1);
}

