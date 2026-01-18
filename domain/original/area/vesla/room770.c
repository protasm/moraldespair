inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Broken Stalls";
    long_desc = "Splintered stall walls lean inward, their rails slick with mildew. A cracked feeding trough sits dry, and dust lies thick where hooves once churned.";
    dest_dir = ({
        "domain/original/area/vesla/room790", "south",
        "domain/original/area/vesla/room765", "west",
        "domain/original/area/vesla/room773", "east",
        "domain/original/area/vesla/room791", "north",
    });
}

