inherit "room/room";

void create() {
  ::create();

    short_desc = "West River Track";
    long_desc = "Moss clings to the low curb here, and the road narrows between leaning facades. Rusted rings jut from the masonry, their purpose long gone.";
    dest_dir = ({
        "chapter/prologue/area/ruined/room146", "east",
        "chapter/prologue/area/ruined/room144", "west",
    });

  set_light(1);
}
