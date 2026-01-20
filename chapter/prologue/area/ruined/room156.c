inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "South Road";
    long_desc = "Broken cobbles gather near a collapsed stoop. The main road is silent, its centerline marked by a shallow rut.";
    dest_dir = ({
        "chapter/prologue/area/ruined/room155", "south",
        "chapter/prologue/area/ruined/room822", "west",
        "chapter/prologue/area/ruined/room424", "east",
        "chapter/prologue/area/ruined/room157", "north",
    });
}


