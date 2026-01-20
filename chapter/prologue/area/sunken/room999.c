inherit "room/room";

void create() {
  ::create();

  short_desc = "Collapsed Approach";
  long_desc = "A straight corridor of paving is split by collapsed slabs and sinkholes. Small pits and cracks show where repeated blows split the surface.";
  dest_dir = ({
    "chapter/prologue/area/sunken/room103", "west",
  });

  set_light(1);
}
