inherit "/room/room";

void create() {
  ::create();

  short_desc = "Sand-Choked Lane";
  long_desc = "A wide run of cracked stone stretches north and south, its center scoured to dust. Soot stains cling to the stone, and the air tastes of old smoke. No footprints remain; only layered grit records the years.";
  dest_dir = ({
    "chapter/prologue/area/sunken/room111", "west",
  });

  set_light(1);
}
