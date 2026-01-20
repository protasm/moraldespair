inherit "room/room";

void create() {
  ::create();

    short_desc = "Basalt River Corner";
    long_desc = "Cracked basalt paving meets the river road, its stones slick with old stains. A collapsed wall spills rubble into the corner, and weeds root in the gaps.";
    dest_dir = ({
        "chapter/prologue/area/ruined/room144", "east",
        "chapter/prologue/area/ruined/room142", "north",
    });

  set_light(1);
}
