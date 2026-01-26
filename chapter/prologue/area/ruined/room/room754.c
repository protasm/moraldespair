inherit "/chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Twin Shadows";
  long_desc = "Two battered towers hem in this passage, their upper floors cracked and open to the sky. Loose stones and damp rubble gather where a wooden span once steadied the gap.";
  dest_dir = ([
    "south":"/chapter/prologue/area/ruined/room/room753",
    "north":"/chapter/prologue/area/ruined/room/room755",
  ]);

}
