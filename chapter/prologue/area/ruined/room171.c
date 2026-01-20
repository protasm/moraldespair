inherit "room/room";

void create() {
  ::create();

    short_desc = "Wall Road";
    long_desc = "The wall runs north and south beside a straight stretch of empty road, its cobbles split by weeds and grit. The silence here is only broken by a faint, steady draft along the stone.";
    dest_dir = ({
        "chapter/prologue/area/ruined/room170", "west",
    });

  set_light(1);
}
