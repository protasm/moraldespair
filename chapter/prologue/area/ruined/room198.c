inherit "room/room";

void create() {
  ::create();

  short_desc = "Sunken Way";
  long_desc = "The old paving has slumped into a shallow trough, stones split and slick with moss. Dust and leaf mold blanket the centerline, and rusted iron bands lie half-buried where something once hung above the road.";
  dest_dir = ([
    "south":"/chapter/prologue/area/ruined/room199",
    "east":"/chapter/prologue/area/ruined/room857",
    "north":"/chapter/prologue/area/ruined/room197",
  ]);

  set_light(1);
}
