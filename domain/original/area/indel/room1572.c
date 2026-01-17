inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "Broken Cold Narrow Way";
    long_desc = "The surface dips and rises where blocks have settled, leaving sharp lips and\n"
                "hollows. Walls to either side are chewed by blasts and blade scars, their faces\n"
                "peeled away.\n"
                "\n"
                "The way runs on in a narrow line, hemmed by broken walls left to weather. Thin\n"
                "lichen mats the shaded edges, and the air tastes of wet dust.\n";
    dest_dir = ({
        "domain/original/area/indel/room1573", "east",
        "domain/original/area/indel/room1571", "west",
    });
}
