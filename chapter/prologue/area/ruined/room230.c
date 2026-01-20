inherit "room/room";

void create() {
  ::create();

    short_desc = "Abandoned Park";
    long_desc = "A once-open lawn is now a tangle of thorn and nettle. Broken edging stones ring the growth like a half-lost border.";
    dest_dir = ([
      "south":"/chapter/prologue/area/ruined/room119",
      "west":"/chapter/prologue/area/ruined/room815",
      "east":"/chapter/prologue/area/ruined/room227",
      "north":"/chapter/prologue/area/ruined/room231",
    ]);

  set_light(1);
}
