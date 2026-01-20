inherit "room/room";

void create() {
  ::create();

    short_desc = "Stone Passage";
    long_desc = "The wall looms close over a cramped passage of worn stone, the gaps filled with dust. Rusty brackets jut from the masonry, and the air carries the chill of old damp.";
    dest_dir = ([
      "east":"/chapter/prologue/area/ruined/room183",
    ]);

  set_light(1);
}

