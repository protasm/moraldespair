inherit "room/room";

void create() {
  ::create();

    short_desc = "West River Track";
    long_desc = "The westward river road is split by frost and root, the stones heaved uneven. A dry gutter runs alongside, packed with silt and curled leaves.";
    dest_dir = ({
        "chapter/prologue/area/ruined/room143", "west",
        "chapter/prologue/area/ruined/room145", "east",
        "chapter/prologue/area/ruined/room847", "south",
    });

  set_light(1);
}
