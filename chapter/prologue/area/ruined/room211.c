inherit "room/room";

void create() {
  ::create();

    short_desc = "River Track End";
    long_desc = "The road ends at a tumbled edge of stone, dropping to a dry, weeded bank. Broken posts stand like stumps along the rim.";
    dest_dir = ([
      "east":"/chapter/prologue/area/ruined/room212",
      "west":"/chapter/prologue/area/ruined/room210",
    ]);

  set_light(1);
}
