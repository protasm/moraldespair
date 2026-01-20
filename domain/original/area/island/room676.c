inherit "room/room";

void create() {
  ::create();


  short_desc = "Mariner's Revenge";
  long_desc = "Mariner's Revenge.\n";
  dest_dir = ([
    "west" : "/domain/original/area/island/room613",
    "north" : "/domain/original/area/island/room677",
  ]);

  set_light(1);
}
