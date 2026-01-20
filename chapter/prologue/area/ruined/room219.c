inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "Cracked Way";
    long_desc = "The street opens slightly, revealing pale stone flecked with lichen. A shallow depression holds rain-dark stains.";
    dest_dir = ({
        "chapter/prologue/area/ruined/room409", "west",
        "chapter/prologue/area/ruined/room218", "south",
        "chapter/prologue/area/ruined/room220", "north",
    });
}
