inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "Smeared Cold Choked End";
    long_desc = "Pitted stone stretches ahead, littered with chips and fragments. Fragments of arches and lintels hang at odd angles, cut and burned through. A collapsed heap chokes the line, the passage left to cave in. Thin lichen mats the shaded edges, and the air tastes of wet dust.";
    dest_dir = ({
        "domain/original/area/indel/room1602", "west",
    });
}
