inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "Shattered Cold Choked End";
    long_desc = "Stone underfoot is split into plates, with grit and ash packed into the seams. Blackened streaks and gouges run along the masonry, breaking any clean line.\n\nA collapsed heap chokes the line, forcing a retreat. Thin lichen mats the shaded edges, and the air tastes of wet dust.\n";
    dest_dir = ({
        "domain/original/area/indel/room1584", "west",
    });
}
