inherit "room/room";

void create() {
  ::create();

    short_desc = "River Track End";
    long_desc = "The road ends at a tumbled edge of stone, dropping to a dry, weeded bank. Broken posts stand like stumps along the rim.";
    dest_dir = ({
        "chapter/prologue/area/ruined/room212", "east",
        "chapter/prologue/area/ruined/room210", "west",
    });

  set_light(1);
}
