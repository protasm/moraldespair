inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "Desolate Park";
    long_desc = "Stone paths fracture beneath a mat of low weeds and windblown soil. A dry\n"
              + "fountain bowl sits cracked and empty under leaning trees.\n";
    dest_dir = ({
        "domain/original/area/vesla/room117", "south",
        "domain/original/area/vesla/room227", "west",
        "domain/original/area/vesla/room172", "east",
        "domain/original/area/vesla/room232", "north",
    });
}
