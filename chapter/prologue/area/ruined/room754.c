inherit "room/room";

void create() {
  ::create();

  short_desc = "Twin Shadows";
  long_desc = "Two battered towers hem in this passage, their upper floors cracked and open to the sky. Loose stones and damp rubble gather where a wooden span once steadied the gap.";
  dest_dir = ({
    "chapter/prologue/area/ruined/room753", "south",
    "chapter/prologue/area/ruined/room755", "north",
  });

  set_light(1);
}
