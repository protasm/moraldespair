inherit "room/room";

void create() {
  ::create();

  short_desc = "Shadow Cut";
  long_desc = "This narrow cut between walls is choked with grit and damp rot. Mildew climbs the stones, and a broken crate hints at rough dealings that once hid here.";
  dest_dir = ({
    "chapter/prologue/area/ruined/room129", "north",
  });

  set_light(1);
}
