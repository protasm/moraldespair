inherit "room/room";

void create() {
  ::create();

  short_desc = "Dull Chime";
  long_desc = "Broken molds and a rusted frame lie in silent dust, the shop in ruin. Rot and mildew stain the stone, hinting at chimes once shaped here in neglect.";
  dest_dir = ([
    "east":"/chapter/prologue/area/ruined/room214",
  ]);

  set_light(1);
}
