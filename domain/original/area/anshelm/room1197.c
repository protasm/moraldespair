inherit "room/room";

void create() {
  ::create();

  short_desc = "Sealed Entry";
  long_desc =
    "A narrow entryway is blocked by a fallen lintel and drifted rubble. Faded\n"
    "plaster still shows hints of old paint.\n";
  dest_dir = ({
    "domain/original/area/anshelm/room281", "south",
  });

  set_light(1);
}
