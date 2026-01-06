inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Foyer of House of Ill Repute";
    long_desc = "Foyer of House of Ill Repute.\n";
    dest_dir = ({
        "domain/original/area/balin/room637", "southwest",
    });
}
