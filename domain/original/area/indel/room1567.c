inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "Split Narrow Way";
    long_desc = "Stone underfoot is split into plates, with grit and ash packed into the seams.\n"
                "Walls to either side are chewed by blasts and blade scars, their faces peeled\n"
                "away.\n"
                "\n"
                "The way runs on in a narrow line, hemmed by broken walls left to weather. Thin\n"
                "lichen mats the shaded edges, and the air tastes of wet dust.\n";
    dest_dir = ({
        "domain/original/area/indel/room1568", "north",
        "domain/original/area/indel/room1566", "south",
    });
}
