inherit "room/room";

void create() {
  ::create();

    short_desc = "Dusty Alcove";
    long_desc = "The chamber is tight and dim, its stone sweating with damp and the floor cluttered with scraps of paper turned to pulp. A broken cabinet and a rusted lockbox lean together in the quiet of long neglect.";
    dest_dir = ([
      "east":"/chapter/prologue/area/ruined/room847",
    ]);

  set_light(1);
}
