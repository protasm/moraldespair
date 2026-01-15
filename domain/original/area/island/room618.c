inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Silver Street";
    long_desc = 
      "The pavement here is fractured and charred, leading toward the jagged\n" +
      "base of a mountain to the north. To the east, the walls of a blackened\n" +
      "structure still radiate a dull, rhythmic heat, pulsing like a dying\n" +
      "ember. Opposite this warmth stands a silent arena, its entrance yawning\n" +
      "open beneath a fixed 'Closed' sign. Thick plumes of steam rise from the\n" +
      "northern rocks, veiling the path where the silver road finally dissolves\n" +
      "into stone and dust.\n";
    dest_dir = ({
        "domain/original/area/island/room617", "south",
        "domain/original/area/island/room622", "west",
        "domain/original/area/island/room691", "east",
        "domain/original/area/island/room619", "north",
    });
}
