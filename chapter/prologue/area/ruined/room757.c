inherit "room/room";

void create() {
  ::create();

  short_desc = "Dust Court";
  long_desc = "Dust drifts along the open court, pooling against slumped walls and empty doorways. The stones are worn smooth in a broad path, the track of forgotten patrols.";
  dest_dir = ({
    "chapter/prologue/area/ruined/room756", "south",
    "chapter/prologue/area/ruined/room765", "northeast",
    "chapter/prologue/area/ruined/room758", "east",
    "chapter/prologue/area/ruined/room766", "north",
  });

  set_light(1);
}
