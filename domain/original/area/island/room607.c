inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "A narrow path between the dunes";
    long_desc = "High, shifting mounds of sand wall in this narrow corridor. To the north,\n" +
      "two salt-pitted stone pillars stand like skeletal sentinels marking a\n" +
      "forgotten threshold. The path leads south toward the sound of the surf\n" +
      "and north toward the looming city silhouette.\n";
        dest_dir = ({
        "domain/original/area/island/room606", "south",
        "domain/original/area/island/room628", "east",
        "domain/original/area/island/room608", "north",
    });
}
