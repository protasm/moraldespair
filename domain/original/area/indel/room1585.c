inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "Eroded Narrow Way";
    long_desc = "Pitted stone stretches ahead, littered with chips and fragments. Leaning walls show long cuts and scorch trails, as if steel and heat worried them for hours. The way runs on in a narrow line, hemmed by broken walls left to weather. Thin lichen mats the shaded edges, and the air tastes of wet dust.\n";
    dest_dir = ({
        "domain/original/area/indel/room1579", "north",
        "domain/original/area/indel/room1586", "south",
    });
}
