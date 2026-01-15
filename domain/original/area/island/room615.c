inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Silver Street";
    long_desc = 
      "The street-stones here possess a cold, unnatural sheen, untouched by\n" +
      "dust or debris. To the south lies the sprawling emptiness of the grand\n" +
      "plaza. Row upon row of metallic torches line the path, their glass\n" +
      "domes emitting a sharp, static hum that vibrates in the stagnant air.\n" +
      "A pale blue luminescence spills from a storefront to the west, while\n" +
      "to the east, the dark canal laps silently against the street's edge.\n";
    dest_dir = ({
        "domain/original/area/island/room688", "west",
        "domain/original/area/island/room614", "south",
        "domain/original/area/island/room616", "north",
    });
}
