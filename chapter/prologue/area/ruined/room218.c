inherit "room/room";

void create() {
  ::create();

    short_desc = "Cracked Way";
    long_desc = "Loose stones crunch under a thin coat of dust. A rusted bracket clings to the wall, its mate long gone.";
    dest_dir = ({
        "chapter/prologue/area/ruined/room217", "south",
        "chapter/prologue/area/ruined/room219", "north",
    });

  set_light(1);
}
