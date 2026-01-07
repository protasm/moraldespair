inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "You trundle past the facade and arrive on a beautiful street.";
    long_desc = "You trundle past the facade and arrive on a beautiful street..\n";
    dest_dir = ({
        "domain/original/area/island/room644", "east",
    });
}
