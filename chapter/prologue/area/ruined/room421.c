inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Sigil Hall";
  long_desc = "Dust lies thick over a ring of cracked tiles, and the air tastes of damp stone. Chipped shelves and a tarnished inlay hint at study and rite, now abandoned.";
  dest_dir = ({
    "chapter/prologue/area/ruined/room132", "north",
  });
}
