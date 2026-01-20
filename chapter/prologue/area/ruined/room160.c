inherit "room/room";

void create() {
  ::create();

    short_desc = "North Road";
    long_desc = "The northward main road rises slightly, its stones pale and chipped. A cold breeze funnels through the gap between empty facades.";
    dest_dir = ({
        "chapter/prologue/area/ruined/room125", "south",
        "chapter/prologue/area/ruined/room412", "east",
        "chapter/prologue/area/ruined/room161", "north",
    });

  set_light(1);
}

