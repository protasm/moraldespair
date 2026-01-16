inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "Pitted Cold Broken Bend";
    long_desc = "The floor is a churn of fractured stone and rubble, pressed flat by time. Blackened streaks and gouges run along the masonry, breaking any clean line. The passage angles hard here, squeezed between stone left to lean and settle. Thin lichen mats the shaded edges, and the air tastes of wet dust.\n";
    dest_dir = ({
        "domain/original/area/indel/room1409", "north",
        "domain/original/area/indel/room1589", "east",
    });
}
