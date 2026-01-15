inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Ledger Room";
  long_desc = "Desks sit in crooked ranks, their drawers swollen and stuck with damp. Mold\n"
              + "frets at the corners of scattered ledgers, and a rusted seal lies half buried\n"
              + "in dust where clerks once tallied.\n";
  dest_dir = ({
    "domain/original/area/vesla/room837", "east",
    "domain/original/area/vesla/room155", "west",
  });
}
