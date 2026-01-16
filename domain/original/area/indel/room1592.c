inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "Cold Narrow Way";
    long_desc = "The surface dips and rises where blocks have settled, leaving sharp lips and hollows. Blackened streaks and gouges run along the masonry, breaking any clean line.\n\nThe way runs on in a narrow line, hemmed by broken walls left to weather. Thin lichen mats the shaded edges, and the air tastes of wet dust.\n";
    dest_dir = ({
        "domain/original/area/indel/room1593", "east",
        "domain/original/area/indel/room1591", "west",
    });
}
