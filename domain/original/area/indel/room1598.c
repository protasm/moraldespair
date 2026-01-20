inherit "room/room";

void create() {
  ::create();

  short_desc = "Cold Split Way";
  long_desc = "The ground is a mosaic of cracked slabs and loose grit, dulled by age. Fragments of arches and lintels hang at odd angles, cut and burned through. The path splits around a heap of fallen blocks, offering lines gone to ruin. Thin lichen mats the shaded edges, and the air tastes of wet dust.";
  dest_dir = ({
    "domain/original/area/indel/room1599", "north",
    "domain/original/area/indel/room1597", "south",
    "domain/original/area/indel/room1600", "east",
  });

  set_light(1);
}
