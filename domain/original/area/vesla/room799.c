inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Reeking Ruin Alley";
    long_desc = "Stagnant filth and ash cling to the broken stones, and a sour reek hangs in the air. The alleyway is collapsed and deserted.\n";
    dest_dir = ({
        "domain/original/area/vesla/room802", "west",
        "domain/original/area/vesla/room800", "east",
        "domain/original/area/vesla/room798", "south",
    });
}
