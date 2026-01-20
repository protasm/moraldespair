inherit "room/room";

void create() {
  ::create();

    short_desc = "Wallside Crossing";
    long_desc = "The crossing sits in the shadow of the inner wall, where the road turns and the stones are slick with old runoff. A gutter cuts across the paving and disappears into rubble.";
    dest_dir = ({
        "chapter/prologue/area/ruined/room181", "west",
        "chapter/prologue/area/ruined/room179", "south",
    });

  set_light(1);
}
