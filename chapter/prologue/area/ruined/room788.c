inherit "room/room";

void create() {
  ::create();

    short_desc = "Iron Post";
    long_desc = "An iron post rises from the floor, its ring eaten with rust. Chaff and dust cake the ground, and the walls weep with damp.";
    dest_dir = ({
        "chapter/prologue/area/ruined/room773", "south",
    });

  set_light(1);
}

