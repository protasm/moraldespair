inherit "room/room";

void create() {
  ::create();

  short_desc = "Quiet Way";
  long_desc =
    "The stone is cracked and uneven, with weeds in the seams. A line of iron pegs\n"
    "runs along one wall.\n";
  dest_dir = ([
    "east" : "/chapter/prologue/area/refuge/room280",
    "west" : "/chapter/prologue/area/refuge/room278",
  ]);

  set_light(1);
}
