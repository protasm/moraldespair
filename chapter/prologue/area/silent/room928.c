inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Old Cemetery";
  long_desc = "Graves spread across a low field, their markers tilted and worn. The ground is\nuneven with sunken plots.\n";
  dest_dir = ({
    "chapter/prologue/area/silent/room926", "west",
  });
}
