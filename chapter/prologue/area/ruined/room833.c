inherit "room/room";

void create() {
  ::create();

  short_desc = "Upper Hall";
  long_desc = "Steps lead to a high room where rain has pooled, leaving dark rings on the stone. Torn ledgers and mildewed banners cling to the walls, and the air is still.";
  dest_dir = ({
    "chapter/prologue/area/ruined/room835", "up",
    "chapter/prologue/area/ruined/room831", "down",
    "chapter/prologue/area/ruined/room834", "west",
  });

  set_light(1);
}
