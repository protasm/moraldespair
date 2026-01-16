inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Armoury";
  long_desc =
    "Hooks and empty racks line the walls of this small armoury. The floor is\n"
    "strewn with rust flakes and rot.\n";
  dest_dir = ({
    "domain/original/area/anshelm/room1155", "up",
  });
}
