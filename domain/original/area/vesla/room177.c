inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Rutted Trade Road";
    long_desc = "Deep ruts and gouges cut through the roadway, as if something massive scraped along it. Ash and shattered stone choke the old caravan path.\n";
    dest_dir = ({
        "domain/original/area/vesla/room176", "south",
        "domain/original/area/vesla/room178", "north",
    });
}
