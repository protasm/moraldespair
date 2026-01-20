inherit "room/room";

void create() {
  ::create();

    short_desc = "Hushed Cots";
    long_desc = "Low bed frames run along the sides, stripped to bare ribs and powdery with dust. The ceiling sags, and the stale air holds the hint of old bedding.";
    dest_dir = ({
        "chapter/prologue/area/ruined/room748", "east",
    });

  set_light(1);
}

