inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Counting Hall";
  long_desc = "A long table runs beneath a broken lintel, its surface coated in dust and rot. Empty cubbies and warped ledgers hint at old records, now blurred by mildew and silence.";
  dest_dir = ({
    "chapter/prologue/area/ruined/room154", "west",
  });
}
