inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "Worn Choked End";
    long_desc = "Grit and broken tiles lie in drifts, the ground uneven and tired. Fragments of arches and lintels hang at odd angles, cut and burned through. A collapsed heap chokes the line, forcing a retreat. Thin lichen mats the shaded edges, and the air tastes of wet dust.\n";
    dest_dir = ({
        "domain/original/area/indel/room1514", "south",
    });
}
