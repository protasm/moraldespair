inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Chapel of War";
    long_desc = "Chapel of War";
    dest_dir = ({
        "chapter/prologue/area/ruined/room820", "south",
    });
}
