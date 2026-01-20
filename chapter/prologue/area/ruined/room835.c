inherit "room/room";

void create() {
  ::create();

    short_desc = "City Archives";
    long_desc = "City Archives";
    dest_dir = ({
        "chapter/prologue/area/ruined/room833", "down",
        "chapter/prologue/area/ruined/room836", "west",
    });

  set_light(1);
}
