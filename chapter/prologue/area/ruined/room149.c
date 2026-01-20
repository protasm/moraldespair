inherit "room/room";

void create() {
  ::create();

    short_desc = "West River Track";
    long_desc = "Weeds crowd the seams of the paving, softening the road into a green ribbon. The air is damp and still along the empty course.";
    dest_dir = ({
        "chapter/prologue/area/ruined/room150", "east",
        "chapter/prologue/area/ruined/room148", "west",
    });

  set_light(1);
}
