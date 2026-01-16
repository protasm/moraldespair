inherit "room/room";

void reset(int arg) {
  if (arg)
    return;

  set_light(1);

  short_desc = "Watch Nook";
  long_desc = "A low chamber opens off the court, with arrow slits clogged by rot\n"
    "and mildew. An overturned bench and a rusted hook speak of watchers\n"
    "gone.\n";
  dest_dir = ({
    "domain/original/area/vesla/room760", "northeast",
    "domain/original/area/vesla/room758", "north",
  });
}
