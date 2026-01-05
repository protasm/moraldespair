inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Brushing aside the hanging vines, you walk east into the servants' quarters.";
    long_desc = "Brushing aside the hanging vines, you walk east into the servants' quarters.\n";
    dest_dir = ({
        "domain/original/area/exedoria/room912", "west",
    });
}
