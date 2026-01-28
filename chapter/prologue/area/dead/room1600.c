inherit "/chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Spalled Crossing";
  long_desc = "The floor is a churn of fractured stone and rubble, pressed flat by time. Fragments of arches and lintels hang at odd angles, cut and burned through. The way opens into a broad break where several ruined lines meet in silence. Thin lichen mats the shaded edges, and the air tastes of wet dust.";
  dest_dir = ([
    "north" : "/chapter/prologue/area/dead/room1603",
    "south" : "/chapter/prologue/area/dead/room1602",
    "east" : "/chapter/prologue/area/dead/room1601",
    "west" : "/chapter/prologue/area/dead/room1598",
  ]);

  set_light(1);
}
