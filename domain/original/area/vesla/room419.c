inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Lightless Ruined Alleyway";
    long_desc = "No light reaches this narrow cut between ruins, only soot and broken masonry. The place feels abandoned even by the dragons.\n";
    dest_dir = ({
        "domain/original/area/vesla/room129", "north",
    });
}
