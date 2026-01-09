inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Cindered Junction by a Dead Park";
    long_desc = "Broken flagstones and scorched roots mark a junction that once"
        + " bustled with traffic. Only rubble and silence connect the "
        + "dead streets.\n";
    dest_dir = ({
        "domain/original/area/vesla/room159", "south",
        "domain/original/area/vesla/room126", "west",
        "domain/original/area/vesla/room124", "east",
        "domain/original/area/vesla/room160", "north",
    });
}
