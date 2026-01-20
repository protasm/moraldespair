inherit "room/room";

void create() {
  ::create();

  short_desc = "Narrow Lane";
  long_desc =
    "The lane pinches between tall, close walls of mottled stone. A ribbon of ivy\n"
    "trails down from a broken cornice.\n";
  dest_dir = ({
    "domain/original/area/anshelm/room244", "east",
    "domain/original/area/anshelm/room246", "west",
  });

  set_light(1);
}
