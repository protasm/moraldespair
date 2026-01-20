inherit "room/room";

void create() {
  ::create();

    short_desc = "East River Track";
    long_desc = "Patches of grass push through the joints in the paving here. The river channel beside the road is choked with debris and still.";
    dest_dir = ([
      "east":"/chapter/prologue/area/ruined/room208",
      "west":"/chapter/prologue/area/ruined/room206",
    ]);

  set_light(1);
}
