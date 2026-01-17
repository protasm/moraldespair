inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "Cold Narrow Way";
    long_desc = "The floor is a churn of fractured stone and rubble, pressed flat by time.\n"
                "Leaning walls show long cuts and scorch trails, as if steel and heat worried\n"
                "them for hours. The way runs on in a narrow line, hemmed by broken walls left to\n"
                "weather. Thin lichen mats the shaded edges, and the air tastes of wet dust.\n";
    dest_dir = ({
        "domain/original/area/indel/room1581", "east",
        "domain/original/area/indel/room1579", "west",
    });
}
