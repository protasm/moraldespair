inherit "room/room";

void create() {
  ::create();

  short_desc = "Spalled Crossing";
  long_desc = "The floor is a churn of fractured stone and rubble, pressed flat by time. Fragments of arches and lintels hang at odd angles, cut and burned through. The way opens into a broad break where several ruined lines meet in silence. Thin lichen mats the shaded edges, and the air tastes of wet dust.";
  dest_dir = ({
    "domain/original/area/indel/room1603", "north",
    "domain/original/area/indel/room1602", "south",
    "domain/original/area/indel/room1601", "east",
    "domain/original/area/indel/room1598", "west",
  });

  set_light(1);
}
