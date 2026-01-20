inherit "room/room";

void create() {
  ::create();

    short_desc = "Rutted Road";
    long_desc = "A faint crown in the road has collapsed, leaving a long trough filled with grit and windblown leaves. The surrounding walls are scarred with old smoke stains.";
    dest_dir = ([
      "south":"/chapter/prologue/area/ruined/room175",
      "north":"/chapter/prologue/area/ruined/room177",
    ]);

  set_light(1);
}
