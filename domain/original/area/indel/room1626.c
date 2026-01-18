inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "Choked Silted Choked End";
    long_desc = "Rubble and crushed mortar blanket the surface, slick in places with old damp. The remains of pillars stand jagged, split and fused by old force. A collapsed heap chokes the line, the passage left to cave in. Thin lichen mats the shaded edges, and the air tastes of wet dust.";
    dest_dir = ({
        "domain/original/area/indel/room1404", "east",
    });
}
