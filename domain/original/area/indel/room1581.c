inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "Jagged Cold Narrow Way";
    long_desc = "Rubble and crushed mortar blanket the surface, slick in places with old damp. Leaning walls show long cuts and scorch trails, as if steel and heat worried them for hours. The way runs on in a narrow line, hemmed by broken walls left to weather. Thin lichen mats the shaded edges, and the air tastes of wet dust.\n";
    dest_dir = ({
        "domain/original/area/indel/room1582", "east",
        "domain/original/area/indel/room1580", "west",
    });
}
