inherit "room/room";

void create() {
  ::create();

  short_desc = "Dusty Lane";
  long_desc =
    "The lane is littered with fragments of tile and brick. A broken archway opens\n"
    "into a hollowed shop.\n";
  dest_dir = ({
    "domain/original/area/anshelm/room261", "east",
    "domain/original/area/anshelm/room263", "west",
  });

  set_light(1);
}
