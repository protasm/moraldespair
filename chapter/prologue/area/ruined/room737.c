inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Quiet Office";
    long_desc = "A low hall of stone desks and alcoves sits gutted and still. Mildew darkens the plaster, and empty niches line the walls where records once rested.";
    dest_dir = ({
        "chapter/prologue/area/ruined/room187", "south",
    });
}

