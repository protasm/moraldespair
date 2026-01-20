inherit "room/room";

void create() {
  ::create();

    short_desc = "South Road";
    long_desc = "The southern road narrows between leaning walls. Loose slate and tile litter the paving.";
    dest_dir = ([
      "south":"/chapter/prologue/area/ruined/room156",
      "west":"/chapter/prologue/area/ruined/room823",
      "east":"/chapter/prologue/area/ruined/room830",
      "north":"/chapter/prologue/area/ruined/room158",
    ]);

  set_light(1);
}

