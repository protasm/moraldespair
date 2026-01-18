inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Empty Hall";
    long_desc = "A long chamber holds only the outline of former sleeping spaces, now dusted gray. Moisture streaks the walls, and the floorboards creak under a film of grit.";
    dest_dir = ({
        "domain/original/area/vesla/room741", "west",
    });
}

