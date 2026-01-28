inherit "/chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Armoury";
  long_desc =
    "Hooks and empty racks line the walls of this small armoury. The floor is\n"
    "strewn with rust flakes and rot.\n";
  dest_dir = ([
    "up" : "/chapter/prologue/area/refuge/room1155",
  ]);

  set_light(1);
}
