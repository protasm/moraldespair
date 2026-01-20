inherit "room/room";

void create() {
  ::create();

    short_desc = "South Road";
    long_desc = "Old cart ruts cut through the stones, softened by moss. A toppled beam rests across the gutter.";
    dest_dir = ({
        "chapter/prologue/area/ruined/room824", "west",
        "chapter/prologue/area/ruined/room157", "south",
        "chapter/prologue/area/ruined/room159", "north",
    });

  set_light(1);
}

