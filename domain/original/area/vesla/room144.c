inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "West River Road";
    long_desc = "The westward river road is split by frost and root, the\n"
                + "stones heaved uneven.\n"
                + "A dry gutter runs alongside, packed with silt and curled\n"
                + "leaves.\n";
    dest_dir = ({
        "domain/original/area/vesla/room143", "west",
        "domain/original/area/vesla/room145", "east",
        "domain/original/area/vesla/room847", "south",
    });
}
