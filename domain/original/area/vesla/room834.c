inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Magistrate";
    long_desc = "Magistrate";
    dest_dir = ({
        "domain/original/area/vesla/room833", "east",
    });
}
