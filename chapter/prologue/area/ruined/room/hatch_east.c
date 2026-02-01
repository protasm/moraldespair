inherit "/chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "East Hatch";
  long_desc =
    "This is the east endpoint for the hatch demo, intentionally plain so\n"
    "the commands stand out. Use 'open hatch' or 'close hatch' here, then go\n"
    "west to return.";
}
