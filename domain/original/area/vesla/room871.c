inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "In Gwyneth's bedroom";
    long_desc = "In Gwyneth's bedroom\n";
    dest_dir = ({
        "domain/original/area/vesla/room873", "down",
        "domain/original/area/vesla/room872", "up",
    });
}
