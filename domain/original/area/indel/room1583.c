inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "Cold Broken Bend";
    long_desc = "Loose stones shift underfoot, buried in silt and powdered mortar. Leaning walls show long cuts and scorch trails, as if steel and heat worried them for hours. The passage angles hard here, squeezed between leaning stone. Thin lichen mats the shaded edges, and the air tastes of wet dust.\n";
    dest_dir = ({
        "domain/original/area/indel/room1582", "west",
        "domain/original/area/indel/room1653", "down",
    });
}
