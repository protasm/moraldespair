inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Silver Street";
    long_desc = long_desc = 
      "Smooth, pale stone lines this wide thoroughfare under a stagnant sky.\n" +
      "Dead metallic torches stand in silent intervals, their glow long since\n" +
      "extinguished. To the east, an ornate building rises toward the heavens\n" +
      "with twin, crumbling spires. Opposite the spires, a nameless storefront\n" +
      "stares onto the street with a vacant, open doorway.\n";
    dest_dir = ({
        "domain/original/area/island/room610", "south",
        "domain/original/area/island/room713", "east",
        "domain/original/area/island/room612", "north",
    });
}
