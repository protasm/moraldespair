inherit "room/room";

void reset(int arg) {
  if (arg)
    return;

  set_light(1);

  short_desc = "Wax Shelf";
  long_desc = "Hardened wax pools on a sagging table, silent beneath dust and mildew. Empty molds and a stale tallow smell linger in rot, hinting at candlework long abandoned.";
  dest_dir = ({
    "chapter/prologue/area/ruined/room214", "west",
  });
}
