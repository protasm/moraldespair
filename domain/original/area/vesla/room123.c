inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Cindered Walk by a Dead Park";
    long_desc = "Blackened branches arch over a walkway of cracked flagstones, "
        + "their shade long burned away. The path is quiet, littered with"
        + " ash and broken masonry.\n";
    dest_dir = ({
        "domain/original/area/vesla/room124", "west",
        "domain/original/area/vesla/room122", "east",
        "domain/original/area/vesla/room411", "north",
    });
}
