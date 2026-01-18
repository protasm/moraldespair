inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "West River Track";
    long_desc = "The westward river road is split by frost and root, the stones heaved uneven. A dry gutter runs alongside, packed with silt and curled leaves.";
    dest_dir = ({
        "domain/original/area/vesla/room143", "west",
        "domain/original/area/vesla/room145", "east",
        "domain/original/area/vesla/room847", "south",
    });
}
