inherit "room/room";

void create() {
  ::create();

  short_desc = "Gate Approach";
  long_desc =
    "Broken paving leads up to the archway, scattered with fallen masonry. The\n"
    "flanking towers stand cracked and hollow.\n";
  dest_dir = ({
    "domain/original/area/anshelm/room274", "south",
  });

  set_light(1);
}
