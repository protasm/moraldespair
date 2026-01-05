inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Foyer of the Exedorian Inn";
    long_desc = "Foyer of the Exedorian Inn.\n";
    dest_dir = ({
        "domain/original/area/exedoria/room307", "southeast",
        "domain/original/area/exedoria/room332", "west",
    });
}
