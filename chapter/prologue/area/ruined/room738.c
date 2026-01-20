inherit "room/room";

void create() {
  ::create();

    short_desc = "Blind Alley";
    long_desc = "The alley narrows to a blind wall, its cobbles slick with grime and decay. Rotten beams lean overhead, and a stale dampness pools where the light dies.";
    dest_dir = ({
        "chapter/prologue/area/ruined/room188", "south",
    });

  set_light(1);
}

