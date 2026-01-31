inherit "/chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Sanctuary";
  long_desc = "You stand within the high, vaulted shadows of the Sanctuary. Two centuries ago, this hall was a beacon of hope for die-hard adventurers. Now, the air is cold and tastes of stagnant incense. The glory that once beckoned is long forgotten, replaced by a hollow silence that whispers of a great decay.\n\nYou feel a STRONG urge to... you can't recall?";

  add_exit("south", "room228");
  add_exit("up", "lounge");
  add_exit("down", "portal");
}

void init() {
  add_action("do_foo", "foo");
}

int do_foo() {
  write("foo!\n");

  return 1;
}

int pre_leave(object exit) {
  if(!(exit->use_word() == "south")) return 1;

  write("The way is shut. It was made by those who are Dead, and the Dead keep it, until the time comes. The way is shut.\n");

  return 0;
}
