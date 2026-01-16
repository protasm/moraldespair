inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Sealed Entry";
  long_desc =
    "A narrow entryway is blocked by a fallen lintel and drifted rubble. Faded\n"
    "plaster still shows hints of old paint.\n";
  dest_dir = ({
    "domain/original/area/anshelm/room281", "south",
  });
}
