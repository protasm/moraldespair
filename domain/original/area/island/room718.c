inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Taxidermist";
    long_desc = "Taxidermist.\n";
    dest_dir = ({
        "domain/original/area/island/room635", "southwest",
    });
}
