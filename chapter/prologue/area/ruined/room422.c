inherit "room/room";

void create() {
  ::create();

  short_desc = "Ledger Room";
  long_desc = "Desks sit in crooked ranks, their drawers swollen and stuck with damp. Mold frets at the corners of scattered ledgers, and a rusted seal lies half buried in dust where clerks once tallied.";
  dest_dir = ({
    "chapter/prologue/area/ruined/room837", "east",
    "chapter/prologue/area/ruined/room155", "west",
  });

  set_light(1);
}
