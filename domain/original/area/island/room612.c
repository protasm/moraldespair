inherit "room/room";

void create() {
  ::create();

  set_light(1);
}

  set_light(1);
  short_desc = "Silver Street";
  long_desc = "The pale stones of the street remain eerily clear of debris, as if the\n" +
    "city itself refuses to decay. To the west, a massive, cold furnace marks\n" +
    "the remains of a foundry. The eastern storefront, once smelling of grain\n" +
    "and yeast, now exhales only the scent of damp flour and rot. Northward,\n" +
    "the shadows of monumental structures loom over the cooling metal torches.\n";

  dest_dir = ([
    "north" : "/domain/original/area/island/room613",
    "east" : "/domain/original/area/island/room674",
    "south" : "/domain/original/area/island/room611",
    "west" : "/domain/original/area/island/room642",
  ]);
}
