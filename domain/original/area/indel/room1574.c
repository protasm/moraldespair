inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "Cold Narrow Way";
    long_desc = "Split slabs tilt against each other, their edges worn to chalk. Walls to either\n"
                "side are chewed by blasts and blade scars, their faces peeled away. The way runs\n"
                "on in a narrow line, hemmed by broken walls left to weather. Thin lichen mats\n"
                "the shaded edges, and the air tastes of wet dust.\n";
    dest_dir = ({
        "domain/original/area/indel/room1575", "east",
        "domain/original/area/indel/room1573", "west",
    });
}
