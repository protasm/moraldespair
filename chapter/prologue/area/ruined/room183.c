inherit "room/room";

void create() {
  ::create();

    short_desc = "Cobbled Run";
    long_desc = "Cobbles press against the wall here, split by frost and buckling in the soil. Weeds and dark lichen gather where the stonework weeps, muting any echo.";
    dest_dir = ([
      "east":"/chapter/prologue/area/ruined/room182",
      "west":"/chapter/prologue/area/ruined/room184",
    ]);

  set_light(1);
}


