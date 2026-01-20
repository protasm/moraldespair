inherit "room/room";

void create() {
  ::create();

  short_desc = "Sanctuary";
  long_desc = "You stand within the high, vaulted shadows of the Sanctuary. Two centuries ago, this hall was a beacon of hope for die-hard adventurers. Now, the air is cold and tastes of stagnant incense. The glory that once beckoned is long forgotten, replaced by a hollow silence that whispers of a great decay.\n\nYou feel a STRONG urge to... you can't recall?";
  dest_dir = ([
    "south":"/chapter/prologue/area/ruined/room228",
    "up":"/chapter/prologue/area/ruined/lounge",
    "down":"/chapter/prologue/area/ruined/portal",
  ]);

  set_light(1);
}
