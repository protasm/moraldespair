inherit "room/room";

void create() {
  ::create();

    short_desc = "East River Track";
    long_desc = "The eastern stretch runs straight and hollow, its stones slick with moss. A low wall beside it is buckled and split.";
    dest_dir = ({
        "chapter/prologue/area/ruined/room206", "east",
        "chapter/prologue/area/ruined/room151", "west",
    });

  set_light(1);
}
