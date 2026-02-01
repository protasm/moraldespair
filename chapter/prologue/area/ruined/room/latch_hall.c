inherit "/chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Latch Hall";
  long_desc =
    "This hall exists to show a latch that only locks from the lounge side.\n"
    "From that side, use 'lock latch demo' and 'unlock latch demo', then\n"
    "'open latch'; from here those lock verbs do nothing.";
}
