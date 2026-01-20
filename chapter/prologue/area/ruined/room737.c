inherit "room/room";

void create() {
  ::create();

    short_desc = "Quiet Office";
    long_desc = "A low hall of stone desks and alcoves sits gutted and still. Mildew darkens the plaster, and empty niches line the walls where records once rested.";
    dest_dir = ({
        "chapter/prologue/area/ruined/room187", "south",
    });

  set_light(1);
}

