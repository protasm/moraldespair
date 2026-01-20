inherit "room/room";

void create() {
  ::create();

  short_desc = "Basalt Avenue";
  long_desc = "Basalt paving runs between dark stone walls, the joints split by weeds and grit. A low drift of broken tile lies where slow runoff has carved shallow channels.";
  dest_dir = ({
    "chapter/prologue/area/ruined/room136", "south",
    "chapter/prologue/area/ruined/room133", "north",
  });

  set_light(1);
}
