inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "Dulled Sunk Broken Bend";
    long_desc = "Broken paving lies in uneven ridges, with fine dust caked between. Walls to either side are chewed by blasts and blade scars, their faces peeled away. The passage angles hard here, squeezed between leaning stone. Thin lichen mats the shaded edges, and the air tastes of wet dust.\n";
    dest_dir = ({
        "domain/original/area/indel/room1568", "south",
        "domain/original/area/indel/room1570", "east",
    });
}
