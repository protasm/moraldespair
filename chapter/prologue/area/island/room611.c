inherit "room/room";

void create() {
  ::create();


  short_desc = "Silver Street";
  long_desc = "Smooth, pale stone lines this wide thoroughfare under a stagnant sky.\n" +
    "Dead metallic torches stand in silent intervals, their glow long since\n" +
    "extinguished. To the east, an ornate building rises toward the heavens\n" +
    "with twin, crumbling spires. Opposite the spires, a nameless storefront\n" +
    "stares onto the street with a vacant, open doorway.\n";
  dest_dir = ([
    "south" : "/chapter/prologue/area/island/room610",
    "east" : "/chapter/prologue/area/island/room713",
    "north" : "/chapter/prologue/area/island/room612",
  ]);

  set_light(1);
}
