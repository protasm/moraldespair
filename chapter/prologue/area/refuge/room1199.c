inherit "/chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Old Smithy";
  long_desc =
    "A low shack of stone holds a cold forge and a broken anvil. Rust flakes\n"
    "glitter across the hearth.\n";
  dest_dir = ([
    "north" : "/chapter/prologue/area/refuge/room270",
  ]);

  set_light(1);
}
