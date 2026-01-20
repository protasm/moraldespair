inherit "room/room";

void create() {
  ::create();

    short_desc = "Silent Way";
    long_desc = "The way crosses another street in a small square of worn stone. Old foundations crowd the corners, their rooms open and empty. Wind moves freely through the gaps.";
    dest_dir = ({
        "chapter/prologue/area/ruined/room740", "south",
        "chapter/prologue/area/ruined/room191", "west",
        "chapter/prologue/area/ruined/room189", "east",
        "chapter/prologue/area/ruined/room741", "north",
    });

  set_light(1);
}


