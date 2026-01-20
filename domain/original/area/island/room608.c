inherit "room/room";

void create() {
  ::create();


  short_desc = "A Dune Path";
  long_desc = "Sand gives way to jagged stone as the path climbs toward the city's\n" +
    "outer perimeter. To the north, the monolithic gate towers cast long,\n" +
    "immobile shadows over the shifting ground. The air is thinner here,\n" +
    "carrying only the scent of dry dust and ancient, sun-baked rock.\n";
  dest_dir = ([
    "south" : "/domain/original/area/island/room607",
    "north" : "/domain/original/area/island/room609",
  ]);

  set_light(1);
}
