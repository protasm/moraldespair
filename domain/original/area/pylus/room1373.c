inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Climbing the tight stairwell, you open the trapdoor and climb to the roof.";
    long_desc = "Climbing the tight stairwell, you open the trapdoor and climb to the roof..\n";
    dest_dir = ({
        "domain/original/area/pylus/room1369", "down",
    });
}
