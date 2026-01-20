inherit "room/room";

void create() {
  ::create();

    short_desc = "Silent Way";
    long_desc = "A long row of broken pillars lines the north side of the way, each stump dark with weathering. The ground is littered with slate chips and fine dust.";
    dest_dir = ({
        "chapter/prologue/area/ruined/room742", "south",
        "chapter/prologue/area/ruined/room192", "west",
        "chapter/prologue/area/ruined/room190", "east",
        "chapter/prologue/area/ruined/room743", "north",
    });

  set_light(1);
}


