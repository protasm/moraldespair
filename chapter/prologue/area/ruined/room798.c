inherit "room/room";

void create() {
  ::create();

  short_desc = "Sour Cut";
  long_desc = "The passage bends in shadow, damp with rot and flecked with peeling lime. A shallow gutter runs along the base of the wall, a remnant of old refuse flow.";
  dest_dir = ([
    "south":"/chapter/prologue/area/ruined/room797",
    "north":"/chapter/prologue/area/ruined/room799",
  ]);

  set_light(1);
}
