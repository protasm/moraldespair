inherit "/chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Workroom";
  long_desc = "Long tables and rusted tools line the walls. A few cracked vessels still rest\non their shelves.\n";
  dest_dir = ([
    "east":"/chapter/prologue/area/silent/room904",
  ]);

  set_light(1);
}
