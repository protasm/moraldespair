inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Record Hall";
    long_desc = "A long chamber sits in silence, its ceiling sagged and its floor layered in\n"
              + "dust and mildew. Split desks and fallen stools crowd the room, and a rusted\n"
              + "rail still divides a row of mildewed pigeonholes.\n";
    dest_dir = ({
        "domain/original/area/vesla/room849", "west",
        "domain/original/area/vesla/room848", "east",
        "domain/original/area/vesla/room144", "north",
    });
}
