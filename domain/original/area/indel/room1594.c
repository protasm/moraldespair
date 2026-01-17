inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "Leaning Broken Bend";
    long_desc = "Split slabs tilt against each other, their edges worn to chalk. Blackened\n"
                "streaks and gouges run along the masonry, breaking any clean line. The passage\n"
                "angles hard here, squeezed between stone left to lean and settle. Thin lichen\n"
                "mats the shaded edges, and the air tastes of wet dust.\n";
    dest_dir = ({
        "domain/original/area/indel/room1593", "south",
        "domain/original/area/indel/room1595", "west",
    });
}
