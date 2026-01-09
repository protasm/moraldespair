inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "Choked Narrow Way";
    long_desc = "Grit and broken tiles lie in drifts, the ground uneven and tired. Walls to either side are chewed by blasts and blade scars, their faces peeled away. The way runs on in a narrow line, hemmed by broken walls. Thin lichen mats the shaded edges, and the air tastes of wet dust.\n";
    dest_dir = ({
        "domain/original/area/indel/room1577", "east",
        "domain/original/area/indel/room1575", "west",
    });
}
