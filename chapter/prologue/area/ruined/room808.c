inherit "room/room";

void create() {
  ::create();

    short_desc = "Livery";
    long_desc = "Livery";
    dest_dir = ({
        "chapter/prologue/area/ruined/room809", "up",
        "chapter/prologue/area/ruined/room161", "west",
    });

  set_light(1);
}
