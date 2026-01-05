inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Cemetery";
    long_desc = "Cemetery.\n";
    dest_dir = ({
        "domain/original/area/exedoria/room926", "west",
    });
}
