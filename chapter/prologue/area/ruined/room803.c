inherit "room/room";

void create() {
  ::create();

    short_desc = "Stink Alley Way";
    long_desc = "Stink Alley Way";
    dest_dir = ({
        "chapter/prologue/area/ruined/room802", "east",
        "chapter/prologue/area/ruined/room804", "south",
    });

  set_light(1);
}
