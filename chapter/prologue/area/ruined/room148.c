inherit "room/room";

void create() {
  ::create();

    short_desc = "West River Track";
    long_desc = "A line of cracked flagstones stretches west, fractured by roots. A low parapet crumbles toward a silent channel, its edge washed bare.";
    dest_dir = ({
        "chapter/prologue/area/ruined/room147", "west",
        "chapter/prologue/area/ruined/room149", "east",
        "chapter/prologue/area/ruined/room840", "north",
    });

  set_light(1);
}
