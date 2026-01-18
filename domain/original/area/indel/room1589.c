inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "Cold Split Way";
    long_desc = "Broken paving lies in uneven ridges, with fine dust caked between. Blackened streaks and gouges run along the masonry, breaking any clean line. The path splits around a heap of fallen blocks, offering lines gone to ruin. Thin lichen mats the shaded edges, and the air tastes of wet dust.";
    dest_dir = ({
        "domain/original/area/indel/room1408", "north",
        "domain/original/area/indel/room1588", "east",
        "domain/original/area/indel/room1590", "west",
    });
}
