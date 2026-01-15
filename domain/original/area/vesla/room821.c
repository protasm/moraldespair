inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Counting Hall";
  long_desc = "A long table runs beneath a broken lintel, its surface coated in dust and rot.\n"
              + "Empty cubbies and warped ledgers hint at old records, now blurred by mildew\n"
              + "and silence.\n";
  dest_dir = ({
    "domain/original/area/vesla/room154", "west",
  });
}
