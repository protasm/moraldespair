inherit "room/room";

void create() {
  ::create();

    short_desc = "A dingy alleyway";
    long_desc = "A dingy alleyway";
    dest_dir = ({
        "chapter/prologue/area/ruined/room410", "south",
        "chapter/prologue/area/ruined/room795", "east",
        "chapter/prologue/area/ruined/room794", "north",
    });

  set_light(1);
}
