inherit "room/room";

void create() {
  ::create();

  short_desc = "Shear Room";
  long_desc = "A narrow room holds a cracked stone basin and a warped chair frame. Rust flakes and dust cover the floor where tools once hung in neat rows.";
  dest_dir = ({
    "chapter/prologue/area/ruined/room800", "south",
  });

  set_light(1);
}
