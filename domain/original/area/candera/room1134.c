inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Cracked Drop";
    long_desc = "The space broadens into a shallow, rubble-filled bowl where paths meet. Rust-red\nstreaks mark where metal once lay, now long gone.\n";
    dest_dir = ({
        "domain/original/area/candera/room69", "down",
    });
}
