inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "Sunk Narrow Way";
    long_desc = "Rubble and crushed mortar blanket the surface, slick in places with old damp. Walls to either side are chewed by blasts and blade scars, their faces peeled away. The way runs on in a narrow line, hemmed by broken walls left to weather. Thin lichen mats the shaded edges, and the air tastes of wet dust.";
    dest_dir = ({
        "domain/original/area/indel/room1572", "east",
        "domain/original/area/indel/room1570", "west",
    });
}
