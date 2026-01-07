inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Ruptured Park Walk";
    long_desc = "The ruined canopy opens to a gap of fallen trees and collapsed paving. Ash swirls where the dragons' fire tore the park apart.\n";
    dest_dir = ({
        "domain/original/area/vesla/room125", "west",
        "domain/original/area/vesla/room123", "east",
        "domain/original/area/vesla/room412", "north",
    });
}
