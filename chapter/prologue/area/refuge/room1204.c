inherit "/room/room";

void create() {
  ::create();

  short_desc = "Quiet Hall";
  long_desc =
    "A wide chamber opens in the keep, its floor swept bare by wind. A carved niche\n"
    "stands empty above a cracked ledge.\n";
  dest_dir = ([
    "east" : "/chapter/prologue/area/refuge/room1143",
  ]);

  set_light(1);
}
