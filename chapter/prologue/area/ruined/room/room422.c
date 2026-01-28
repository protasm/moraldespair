inherit "//chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Ledger Room";
  long_desc = "Desks sit in crooked ranks, their drawers swollen and stuck with damp. Mold frets at the corners of scattered ledgers, and a rusted seal lies half buried in dust where clerks once tallied.";
  dest_dir = ([
    "east":"/chapter/prologue/area/ruined/room/room837",
    "west":"/chapter/prologue/area/ruined/room/room155",
  ]);

}
