inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "The Shadowed Anvil";
    long_desc = "The Shadowed Anvil\n";
    dest_dir = ({
        "domain/original/area/vesla/room220", "west",
        "domain/original/area/vesla/room116", "north",
    });
}
