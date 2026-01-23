inherit "room/room";

void create() {
  ::create();

  short_desc = "Lane End";
  long_desc =
    "The lane narrows to a bend where the stones are nearly buried. A collapsed\n"
    "stoop leaves a shallow pit of rubble.\n";
  dest_dir = ([
    "east" : "/chapter/prologue/area/anshelm/room246",
    "south" : "/chapter/prologue/area/anshelm/room248",
  ]);

  set_light(1);
}
