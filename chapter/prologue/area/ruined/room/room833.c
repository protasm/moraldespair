inherit "//chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Upper Hall";
  long_desc = "Steps lead to a high room where rain has pooled, leaving dark rings on the stone. Torn ledgers and mildewed banners cling to the walls, and the air is still.";
  dest_dir = ([
    "up":"/chapter/prologue/area/ruined/room/room835",
    "down":"/chapter/prologue/area/ruined/room/room831",
    "west":"/chapter/prologue/area/ruined/room/room834",
  ]);

}
