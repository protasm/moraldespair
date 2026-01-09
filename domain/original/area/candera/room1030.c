inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "sunken span";
    long_desc = "A gap between toppled arches forms a narrow throat in the route. Soot stains cling to the stone, and the air tastes of old smoke.\n";
    dest_dir = ({
        "domain/original/area/candera/room29", "north",
        "domain/original/area/candera/room1032", "east",
        "domain/original/area/candera/room1031", "west",
    });
}
