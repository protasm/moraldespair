inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Ruined Northern Gate";
    long_desc = "The northern gate has been smashed and scorched, its arch "
        + "collapsed into the road. Dragonfire left only ruins and "
        + "silence here.\n";
    dest_dir = ({
        "domain/original/area/vesla/room168", "south",
        "domain/original/area/vesla/room753", "northeast",
    });
}
