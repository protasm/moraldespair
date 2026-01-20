inherit "room/room";

void create() {
  ::create();

    short_desc = "Ash Store";
    long_desc = "Low shelves and bins crowd the room, warped and split from damp. Cinder stains and rusted nail heads hint at the forge work once stacked here.";
    dest_dir = ({
        "chapter/prologue/area/ruined/room771", "west",
    });

  set_light(1);
}

