inherit "room/room";

void create() {
  ::create();

  short_desc = "Upper Steps";
  long_desc = "The upper steps rise into a roofless shaft where rain darkens the stone. Loose grit and rust flakes collect along the wall where a rail once ran.";
  dest_dir = ({
    "chapter/prologue/area/ruined/room764", "southwest",
    "chapter/prologue/area/ruined/room761", "down",
  });

  set_light(1);
}
