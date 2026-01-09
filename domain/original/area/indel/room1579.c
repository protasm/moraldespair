inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "Rubble Crossing";
    long_desc = "Broken paving lies in uneven ridges, with fine dust caked between. Leaning walls show long cuts and scorch trails, as if steel and heat worried them for hours. The way opens into a broad break where several lines of ruin meet. Thin lichen mats the shaded edges, and the air tastes of wet dust.\n";
    dest_dir = ({
        "domain/original/area/indel/room1584", "north",
        "domain/original/area/indel/room1585", "south",
        "domain/original/area/indel/room1580", "east",
        "domain/original/area/indel/room1578", "west",
    });
}
