inherit "room/room";

void create() {
  ::create();

    short_desc = "Tether Line";
    long_desc = "A line of rotted posts stands uneven, each marked by rust streaks. The floor is hard and bare, broken only by a drift of grit.";
    dest_dir = ({
        "chapter/prologue/area/ruined/room773", "north",
    });

  set_light(1);
}

