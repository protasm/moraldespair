inherit "room/room";

void create() {
  ::create();


  short_desc = "Silver Street";
  long_desc = 
    "The street-stones here possess a cold, unnatural sheen, untouched by\n" +
    "dust or debris. To the south lies the sprawling emptiness of the grand\n" +
    "plaza. Row upon row of metallic torches line the path, their glass\n" +
    "domes emitting a sharp, static hum that vibrates in the stagnant air.\n" +
    "A pale blue luminescence spills from a storefront to the west, while\n" +
    "to the east, the dark canal laps silently against the street's edge.\n";
  dest_dir = ([
    "west" : "/chapter/prologue/area/island/room688",
    "south" : "/chapter/prologue/area/island/room614",
    "north" : "/chapter/prologue/area/island/room616",
  ]);

  set_light(1);
}
