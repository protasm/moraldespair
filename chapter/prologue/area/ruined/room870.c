inherit "room/room";

void create() {
  ::create();

    short_desc = "In Rohan's bedroom";
    long_desc = "In Rohan's bedroom";
    dest_dir = ({
        "chapter/prologue/area/ruined/room869", "down",
        "chapter/prologue/area/ruined/room871", "up",
    });

  set_light(1);
}
