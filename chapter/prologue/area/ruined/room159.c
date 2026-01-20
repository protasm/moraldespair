inherit "room/room";

void create() {
  ::create();

    short_desc = "South Road";
    long_desc = "The paving stones here are splintered and slick with lichen. Dust lies thick against the bases of the walls.";
    dest_dir = ({
        "chapter/prologue/area/ruined/room158", "south",
        "chapter/prologue/area/ruined/room125", "north",
    });

  set_light(1);
}


