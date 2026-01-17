inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "Smeared Narrow Way";
    long_desc = "The floor is a churn of fractured stone and rubble, pressed flat by time. Walls\n"
                "to either side are chewed by blasts and blade scars, their faces peeled away.\n"
                "The way runs on in a narrow line, hemmed by broken walls left to weather. Thin\n"
                "lichen mats the shaded edges, and the air tastes of wet dust.\n";
    dest_dir = ({
        "domain/original/area/indel/room1571", "east",
        "domain/original/area/indel/room1569", "west",
    });
}
