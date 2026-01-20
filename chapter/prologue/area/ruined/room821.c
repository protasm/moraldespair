inherit "room/room";

void create() {
  ::create();

  short_desc = "Counting Hall";
  long_desc = "A long table runs beneath a broken lintel, its surface coated in dust and rot. Empty cubbies and warped ledgers hint at old records, now blurred by mildew and silence.";
  dest_dir = ([
    "west":"/chapter/prologue/area/ruined/room154",
  ]);

  set_light(1);
}
