inherit "room/room";

void create() {
  ::create();

  short_desc = "Tight Passage";
  long_desc =
    "A narrow passage squeezes between two thick walls of stone. The floor is\n"
    "polished smooth where many feet once passed.\n";
  dest_dir = ([
    "west" : "/chapter/prologue/area/refuge/room265",
  ]);

  set_light(1);
}
