inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Rutted Road";
    long_desc = "A faint crown in the road has collapsed, leaving a long trough\n"
              + "filled with grit and windblown leaves. The surrounding walls are\n"
              + "scarred with old smoke stains.\n";
    dest_dir = ({
        "domain/original/area/vesla/room175", "south",
        "domain/original/area/vesla/room177", "north",
    });
}
