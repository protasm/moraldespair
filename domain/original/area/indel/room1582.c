inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "Ashen Narrow Way";
    long_desc = "The surface dips and rises where blocks have settled, leaving sharp lips and hollows. Leaning walls show long cuts and scorch trails, as if steel and heat worried them for hours. The way runs on in a narrow line, hemmed by broken walls left to weather. Thin lichen mats the shaded edges, and the air tastes of wet dust.";
    dest_dir = ({
        "domain/original/area/indel/room1583", "east",
        "domain/original/area/indel/room1581", "west",
    });
}
