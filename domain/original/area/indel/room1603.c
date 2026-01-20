inherit "room/room";

void create() {
  ::create();

  short_desc = "Bleached Broken Bend";
  long_desc = "Loose stones shift underfoot, buried in silt and powdered mortar. Fragments of arches and lintels hang at odd angles, cut and burned through. The passage angles hard here, squeezed between stone left to lean and settle. Thin lichen mats the shaded edges, and the air tastes of wet dust.";
  dest_dir = ({
    "domain/original/area/indel/room1600", "south",
    "domain/original/area/indel/room1604", "east",
  });

  set_light(1);
}
