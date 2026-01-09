inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "Cold Choked End";
    long_desc = "Grit and broken tiles lie in drifts, the ground uneven and tired. Leaning walls show long cuts and scorch trails, as if steel and heat worried them for hours. A collapsed heap chokes the line, forcing a retreat. Thin lichen mats the shaded edges, and the air tastes of wet dust.\n";
    dest_dir = ({
        "domain/original/area/indel/room1585", "north",
    });
}
