inherit "room/room";

void create() {
  ::create();

  short_desc = "Faded Choked End";
  long_desc = "Pitted stone stretches ahead, littered with chips and fragments. Fragments of arches and lintels hang at odd angles, cut and burned through. A collapsed heap chokes the line, the passage left to cave in. Moss and pale mold cling to the damp pockets, and nothing moves except drifting grit.";
  dest_dir = ({
    "domain/original/area/indel/room1438", "north",
  });

  set_light(1);
}
