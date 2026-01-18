inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Shadow Cut";
  long_desc = "This narrow cut between walls is choked with grit and damp rot. Mildew climbs the stones, and a broken crate hints at rough dealings that once hid here.";
  dest_dir = ({
    "domain/original/area/vesla/room129", "north",
  });
}
