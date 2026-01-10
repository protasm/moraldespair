inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "West River Track";
    long_desc = "Moss clings to the low curb here, and the road narrows\n"
                + "between leaning facades.\n"
                + "Rusted rings jut from the masonry, their purpose long\n"
                + "gone.\n";
    dest_dir = ({
        "domain/original/area/vesla/room146", "east",
        "domain/original/area/vesla/room144", "west",
    });
}
