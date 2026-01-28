inherit "//chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Shuttered Shop";
  long_desc = "A narrow storefront sits silent, its signboard fallen into the street. The\ninterior is stripped and open to weather.\n";
  dest_dir = ([
    "north":"/chapter/prologue/area/silent/room300",
  ]);

  set_light(1);
}
