inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Sand-Choked Lane";
    long_desc = "A wide run of cracked stone stretches north and south, its center scoured to\ndust. Soot stains cling to the stone, and the air tastes of old smoke.\n\nNo footprints remain; only layered grit records the years.\n";
    dest_dir = ({
        "domain/original/area/candera/room57", "south",
        "domain/original/area/candera/room2", "east",
        "domain/original/area/candera/room56", "west",
	"domain/original/area/roadway/room1", "exit",
    });
}
