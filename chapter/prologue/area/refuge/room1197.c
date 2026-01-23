inherit "room/room";

void create() {
  ::create();

  short_desc = "Sealed Entry";
  long_desc =
    "A narrow entryway is blocked by a fallen lintel and drifted rubble. Faded\n"
    "plaster still shows hints of old paint.\n";
  dest_dir = ([
    "south" : "/chapter/prologue/area/refuge/room281",
  ]);

  set_light(1);
}
