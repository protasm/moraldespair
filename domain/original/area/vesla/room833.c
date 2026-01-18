inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Upper Hall";
  long_desc = "Steps lead to a high room where rain has pooled, leaving dark rings on the stone. Torn ledgers and mildewed banners cling to the walls, and the air is still.";
  dest_dir = ({
    "domain/original/area/vesla/room835", "up",
    "domain/original/area/vesla/room831", "down",
    "domain/original/area/vesla/room834", "west",
  });
}
