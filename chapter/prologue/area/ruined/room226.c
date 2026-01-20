inherit "room/room";

void create() {
  ::create();

    short_desc = "Desolate Park";
    long_desc = "Stone paths fracture beneath a mat of low weeds and windblown soil. A dry fountain bowl sits cracked and empty under leaning trees.";
    dest_dir = ({
        "chapter/prologue/area/ruined/room117", "south",
        "chapter/prologue/area/ruined/room227", "west",
        "chapter/prologue/area/ruined/room172", "east",
        "chapter/prologue/area/ruined/room232", "north",
    });

  set_light(1);
}
