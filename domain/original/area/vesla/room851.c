inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Cinder-Laden Court";
    long_desc = "The ceiling has partially collapsed, leaving jagged stone and "
        + "ash. The destruction feels deliberate, as if wrought by "
        + "enormous, fire-breathing beasts.\n";
    dest_dir = ({
        "domain/original/area/vesla/room850", "south",
    });
}
