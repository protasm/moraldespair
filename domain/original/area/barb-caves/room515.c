inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Bottom of a Deep Dark Pit";
    long_desc = "Bottom of a Deep Dark Pit.\n";
    dest_dir = ({
        "domain/original/area/barb-caves/room516", "east",
        "domain/original/area/barb-caves/room513", "north",
        "chapter/prologue/area/ruined/portal", "vesla",
    });
}
