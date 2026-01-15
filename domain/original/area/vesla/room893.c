inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "The Players' lounge";
    long_desc = "You stand in the hollowed remains of the lounge, a room that once buzzed with the gossip and fevered arguments of long-dead legends. Now, the only sound is the whistling of wind through the cracked, soot-stained windows that line the walls. A shimmering blue portal still flickers weakly in the center, its light pulsing like a dying heart as it leads upward. On the south wall, a massive map is nailed to the stone; it is yellowed and brittle, showing a world that no longer exists. Faded inscriptions on the floor hint at forgotten powers: <describe>, <hmessage>, <title>, <size>, <fixtitle>, and <apply>.";
    dest_dir = ({
        "domain/original/area/vesla/sanctuary", "down",
    });
}

