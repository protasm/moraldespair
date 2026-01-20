inherit "room/room";

void create() {
  ::create();


  short_desc = "Mariner's Revenge";
  long_desc = "Mariner's Revenge.\n";
  dest_dir = ({
    "domain/original/area/island/room613", "west",
    "domain/original/area/island/room677", "north",
  });

  set_light(1);
}
