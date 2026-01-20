inherit "room/room";

void create() {
  ::create();

    short_desc = "Record Hall";
    long_desc = "A long chamber sits in silence, its ceiling sagged and its floor layered in dust and mildew. Split desks and fallen stools crowd the room, and a rusted rail still divides a row of mildewed pigeonholes.";
    dest_dir = ({
        "chapter/prologue/area/ruined/room849", "west",
        "chapter/prologue/area/ruined/room848", "east",
        "chapter/prologue/area/ruined/room144", "north",
    });

  set_light(1);
}
