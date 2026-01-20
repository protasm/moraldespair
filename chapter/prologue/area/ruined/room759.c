inherit "room/room";

void create() {
  ::create();

  short_desc = "Watch Nook";
  long_desc = "A low chamber opens off the court, with arrow slits clogged by rot and mildew. An overturned bench and a rusted hook speak of watchers gone.";
  dest_dir = ({
    "chapter/prologue/area/ruined/room760", "northeast",
    "chapter/prologue/area/ruined/room758", "north",
  });

  set_light(1);
}
