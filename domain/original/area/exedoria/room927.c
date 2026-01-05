inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Garden of Machines";
    long_desc = "Garden of Machines.\n";
    dest_dir = ({
        "domain/original/area/exedoria/room926", "east",
    });
}
