inherit "room/room";

void create() {
  ::create();

    short_desc = "South Road";
    long_desc = "The paving stones here are splintered and slick with lichen. Dust lies thick against the bases of the walls.";
    dest_dir = ([
      "south":"/chapter/prologue/area/ruined/room158",
      "north":"/chapter/prologue/area/ruined/room125",
    ]);

  set_light(1);
}


