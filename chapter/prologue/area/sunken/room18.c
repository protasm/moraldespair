inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Sunken Span";
    long_desc = "A gap between toppled arches forms a narrow throat in the route. Soot stains cling to the stone, and the air tastes of old smoke.";
    dest_dir = ({
        "chapter/prologue/area/sunken/room17", "north",
        "chapter/prologue/area/sunken/room19", "south",
    });
}
