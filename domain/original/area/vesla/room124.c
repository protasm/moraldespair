inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Ruptured Walk by a Dead Park";
    long_desc = "The ruined canopy opens to a gap of fallen trees and collapsed"
        + " paving. Ash swirls where blistering heat tore the park apart,"
        + " and bone shards lie in the loam.\n";
    dest_dir = ({
        "domain/original/area/vesla/room125", "west",
        "domain/original/area/vesla/room123", "east",
        "domain/original/area/vesla/room412", "north",
    });
}
