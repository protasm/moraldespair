inherit "/room/room";

void create() {
  ::create();

  short_desc = "Quiet Street";
  long_desc =
    "A narrow street of pale stone stretches between blank walls. Rusted iron\n"
    "brackets jut where balconies once hung.\n";
  dest_dir = ([
    "west" : "/chapter/prologue/area/refuge/room413",
    "south" : "/chapter/prologue/area/refuge/room237",
    "north" : "/chapter/prologue/area/refuge/room239",
  ]);

  set_light(1);
}
