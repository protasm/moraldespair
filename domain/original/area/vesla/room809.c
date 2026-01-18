inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Hayloft";
    long_desc = "Hayloft";
    dest_dir = ({
        "domain/original/area/vesla/room808", "down",
    });
}
