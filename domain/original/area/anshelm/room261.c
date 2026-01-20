inherit "room/room";

void create() {
  ::create();

  short_desc = "Stone Lane";
  long_desc =
    "A straight lane runs east and west through close-set houses. The walls show\n"
    "traces of pale paint and old murals.\n";
  dest_dir = ({
    "domain/original/area/anshelm/room260", "east",
    "domain/original/area/anshelm/room262", "west",
  });

  set_light(1);
}
