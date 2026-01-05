inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Intersection of Rue du Nord and East Geld Strasse";
    long_desc = "Intersection of Rue du Nord and East Geld Strasse.\n";
    dest_dir = ({
        "domain/original/area/anshelm/room259", "west",
        "domain/original/area/anshelm/room281", "east",
        "domain/original/area/anshelm/room257", "south",
    });
}
