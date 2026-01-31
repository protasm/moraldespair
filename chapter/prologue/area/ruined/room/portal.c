inherit "/chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Portal Room";
  long_desc = "This is the portal room. As development continues, these areas will be removed from the portal room and linked to the full world.";

  add_exit("up", "sanctuary");
  add_exit("island", "/chapter/prologue/area/island/room605");
  add_exit("preserve", "/domain/original/area/preserve/room432");
  add_exit("forest", "/domain/original/area/forest/room529");
  add_exit("pylus", "/domain/original/area/pylus/room1205");
  add_exit("green", "/domain/original/area/village-green/room1687");
  add_exit("caves", "/domain/original/area/barb-caves/room515");
}
