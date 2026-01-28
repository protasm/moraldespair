inherit "//chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Dorm Foyer";
  long_desc = "A plain foyer opens into several small chambers. Dust lies thick where beds\nonce stood.\n";
  dest_dir = ([
    "west":"/chapter/prologue/area/silent/room528",
    "south":"/chapter/prologue/area/silent/room895",
    "north":"/chapter/prologue/area/silent/room903",
  ]);

  set_light(1);
}
