inherit "room/room";

void create() {
  ::create();

    short_desc = "Silent Way";
    long_desc = "The paving here is uneven, with gaps where stones have been pulled free or sunk. A narrow passage to the south is choked with grit and a slow spread of grass.";
    dest_dir = ({
        "chapter/prologue/area/ruined/room190", "west",
        "chapter/prologue/area/ruined/room188", "east",
        "chapter/prologue/area/ruined/room739", "south",
    });

  set_light(1);
}


