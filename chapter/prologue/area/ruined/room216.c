inherit "room/room";

void create() {
  ::create();

    short_desc = "Cracked Way";
    long_desc = "A shallow channel cuts along the path, filled with grit and broken tile. The air is cool and still between the close walls.";
    dest_dir = ({
        "chapter/prologue/area/ruined/room215", "south",
        "chapter/prologue/area/ruined/room402", "west",
        "chapter/prologue/area/ruined/room403", "east",
        "chapter/prologue/area/ruined/room217", "north",
    });

  set_light(1);
}
