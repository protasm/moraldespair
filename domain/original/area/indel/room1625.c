inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "Silted Choked End";
    long_desc = "The floor is a churn of fractured stone and rubble, pressed flat by time. The remains of pillars stand jagged, split and fused by old force. A collapsed heap chokes the line, the passage left to cave in. Thin lichen mats the shaded edges, and the air tastes of wet dust.";
    dest_dir = ({
        "domain/original/area/indel/room1405", "east",
    });
}
