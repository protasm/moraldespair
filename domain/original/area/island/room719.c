inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Weaver's";
    long_desc = "Weaver's.\n";
    dest_dir = ({
        "domain/original/area/island/room635", "southeast",
    });
}
