inherit "room/room";

void create() {
  ::create();

    short_desc = "Hollow Counter";
    long_desc = "A cracked counter stretches across the room, with empty racks behind it. Rot has crept into the floorboards, and mildew stains blur whatever goods once stood here.";
    dest_dir = ({
        "chapter/prologue/area/ruined/room191", "south",
    });

  set_light(1);
}

