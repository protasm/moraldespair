inherit "room/room";

void create() {
  ::create();

    short_desc = "In Gwyneth's bedroom";
    long_desc = "In Gwyneth's bedroom";
    dest_dir = ({
        "chapter/prologue/area/ruined/room873", "down",
        "chapter/prologue/area/ruined/room872", "up",
    });

  set_light(1);
}
