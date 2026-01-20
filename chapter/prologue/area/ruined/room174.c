inherit "room/room";

void create() {
  ::create();

    short_desc = "Rutted Road";
    long_desc = "A stretch of broken cobbles continues through the husks of old shops, their beams exposed to sky. Weeds knot in the joints where carts once passed.";
    dest_dir = ({
        "chapter/prologue/area/ruined/room173", "south",
        "chapter/prologue/area/ruined/room175", "north",
    });

  set_light(1);
}
