inherit "/chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Players' Lounge";
  long_desc = "You stand in the hollowed remains of the lounge, a room that once buzzed with the gossip and fevered arguments of long-dead legends. Now, the only sound is the whistling of wind through the cracked, soot-stained windows that line the walls. A shimmering blue portal still flickers weakly in the center, its light pulsing like a dying heart as it leads upward.";

  dest_dir = ([
    "down": "/chapter/prologue/area/ruined/room/sanctuary",
  ]);
}

