inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "Cracked Way";
    long_desc = "The street opens slightly, revealing pale stone flecked with lichen. A shallow depression holds rain-dark stains.";
    dest_dir = ({
        "domain/original/area/vesla/room409", "west",
        "domain/original/area/vesla/room218", "south",
        "domain/original/area/vesla/room220", "north",
    });
}
