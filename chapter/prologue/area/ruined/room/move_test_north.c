inherit "/chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Movement Testing Room";
  long_desc = "This is the Movement Testing Room to the north of the Players' Lounge.";

  add_exit("south", "lounge");
}

