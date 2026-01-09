inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "Lichen Narrow Way";
    long_desc = "The ground is a mosaic of cracked slabs and loose grit, dulled by age. Blackened streaks and gouges run along the masonry, breaking any clean line. The way runs on in a narrow line, hemmed by broken walls. Thin lichen mats the shaded edges, and the air tastes of wet dust.\n";
    dest_dir = ({
        "domain/original/area/indel/room1584", "east",
        "domain/original/area/indel/room1589", "west",
    });
}
