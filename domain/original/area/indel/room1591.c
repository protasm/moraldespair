inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "Stained Narrow Way";
    long_desc = "Rubble and crushed mortar blanket the surface, slick in places with old damp. Blackened streaks and gouges run along the masonry, breaking any clean line. The way runs on in a narrow line, hemmed by broken walls. Thin lichen mats the shaded edges, and the air tastes of wet dust.\n";
    dest_dir = ({
        "domain/original/area/indel/room1592", "east",
        "domain/original/area/indel/room1542", "west",
    });
}
