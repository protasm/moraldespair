inherit "room/room";

void create() {
  ::create();

  short_desc = "Lane End";
  long_desc =
    "The lane narrows to a bend where the stones are nearly buried. A collapsed\n"
    "stoop leaves a shallow pit of rubble.\n";
  dest_dir = ({
    "domain/original/area/anshelm/room246", "east",
    "domain/original/area/anshelm/room248", "south",
  });

  set_light(1);
}
