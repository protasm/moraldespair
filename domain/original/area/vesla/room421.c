inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Sigil Hall";
  long_desc = "Dust lies thick over a ring of cracked tiles, and the air tastes of damp stone.\n"
              + "Chipped shelves and a tarnished inlay hint at study and rite, now abandoned.\n";
  dest_dir = ({
    "domain/original/area/vesla/room132", "north",
  });
}
