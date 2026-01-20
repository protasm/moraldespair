inherit "room/room";

void create() {
  ::create();

  short_desc = "Silent Court";
  long_desc = "Silence hangs in this inner court where weeds thread between cracked stones. A low step and a cracked curb trace where carts once turned.";
  dest_dir = ({
    "chapter/prologue/area/ruined/room757", "west",
    "chapter/prologue/area/ruined/room759", "south",
    "chapter/prologue/area/ruined/room766", "northwest",
    "chapter/prologue/area/ruined/room765", "north",
  });

  set_light(1);
}
