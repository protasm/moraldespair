inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Rutted Road";
    long_desc = "A faint crown in the road has collapsed, leaving a long trough filled with grit and windblown leaves. The surrounding walls are scarred with old smoke stains.";
    dest_dir = ({
        "chapter/prologue/area/ruined/room175", "south",
        "chapter/prologue/area/ruined/room177", "north",
    });
}
