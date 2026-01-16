inherit "room/room";

void reset(int arg) {
  if (arg)
    return;

  set_light(1);

  short_desc = "Dust Court";
  long_desc = "Dust drifts along the open court, pooling against slumped walls and\n"
    "empty doorways. The stones are worn smooth in a broad path, the\n"
    "track of forgotten patrols.\n";
  dest_dir = ({
    "domain/original/area/vesla/room756", "south",
    "domain/original/area/vesla/room765", "northeast",
    "domain/original/area/vesla/room758", "east",
    "domain/original/area/vesla/room766", "north",
  });
}
