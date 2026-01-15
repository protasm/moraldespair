inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "The Players' lounge";
    long_desc = "You stand in the hollowed remains of the lounge, a room that once buzzed with\n" +
	        "the gossip and fevered arguments of long-dead legends. Now, the only sound is\n" +
		"the whistling of wind through the cracked, soot-stained windows that line the\n" +
		"walls. A shimmering blue portal still flickers weakly in the center, its light\n" +
		"pulsing like a dying heart as it leads upward. On the south wall, a massive map\n" +
		"is nailed to the stone; it is yellowed and brittle, showing a world that no\n" +
		"longer exists. Faded inscriptions on the floor hint at forgotten powers.\n";
    dest_dir = ({
        "domain/original/area/vesla/sanctuary", "down",
    });
}

