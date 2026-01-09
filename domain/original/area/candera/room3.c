inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Collapsed Approach";
    long_desc = "A straight corridor of paving is split by collapsed slabs and sinkholes. Small\npits and cracks show where repeated blows split the surface.\n";
    dest_dir = ({
        "domain/original/area/candera/room4", "east",
        "domain/original/area/candera/room2", "west",
    });
}
