inherit "room/room";

void create() {
  ::create();

  short_desc = "Ruined City";
  long_desc = "The ruins of a large city.";
  dest_dir = ({
    "domain/original/area/roadway/room30", "north",
    "domain/original/area/roadway/room43", "south",
    "domain/original/area/roadway/room13", "west",
    "domain/original/area/roadway/room16", "east",
    "chapter/prologue/area/ruined/room115", "city",
  });

  add_exit_alias("c", "city");

  set_light(1);
}
