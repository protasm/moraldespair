inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "Sundered Choked End";
    long_desc = "Broken paving lies in uneven ridges, with fine dust caked between. The remains of pillars stand jagged, split and fused by old force. A collapsed heap chokes the line, forcing a retreat. Thin lichen mats the shaded edges, and the air tastes of wet dust.\n";
    dest_dir = ({
        "domain/original/area/indel/room1509", "south",
    });
}
