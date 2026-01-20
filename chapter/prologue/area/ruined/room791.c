inherit "room/room";

void create() {
  ::create();

    short_desc = "Littered Pen";
    long_desc = "A pen lies open and collapsed, its boards scattered and softened by rot. The stone base is stained dark, and the air hangs damp and still.";
    dest_dir = ({
        "chapter/prologue/area/ruined/room770", "south",
    });

  set_light(1);
}

