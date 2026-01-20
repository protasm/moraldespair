inherit "room/room";

void create() {
  ::create();

  short_desc = "Ruined City";
  long_desc = "The ruins of a large city.";
  dest_dir = ({
    "chapter/prologue/area/roadway/room30", "north",
    "chapter/prologue/area/roadway/room43", "south",
    "chapter/prologue/area/roadway/room13", "west",
    "chapter/prologue/area/roadway/room16", "east",
    "chapter/prologue/area/ruined/room115", "city",
  });

  add_exit_alias("c", "city");

  set_light(1);
}
