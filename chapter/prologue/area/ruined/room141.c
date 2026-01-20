inherit "room/room";

void create() {
  ::create();

  short_desc = "Basalt Avenue";
  long_desc = "Basalt Avenue runs between low facades, their lintels split and worn with age. Thin grass pushes through the cracks, and loose stones have slid into the road.";
  dest_dir = ({
    "chapter/prologue/area/ruined/room142", "south",
    "chapter/prologue/area/ruined/room140", "north",
  });

  set_light(1);
}
