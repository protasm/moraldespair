inherit "room/room";

void create() {
  ::create();

    short_desc = "Moldy Loft";
    long_desc = "A low loft space is sunk and split, its ladder gone. Mold spreads across the rafters, and a dull dampness fills the room.";
    dest_dir = ({
        "chapter/prologue/area/ruined/room776", "north",
    });

  set_light(1);
}

