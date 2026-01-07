inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Archway of Servitude";
    long_desc = "Archway of Servitude.\n";
    dest_dir = ({
        "domain/original/area/balin/room725", "south",
        "domain/original/area/balin/room723", "north",
    });
}
