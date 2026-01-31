inherit "/chapter/prologue/std/link_room";

void create() {
  ::create();

  short_desc = "Lower Vault";
  long_desc = "A low vault collects silt and pebbles beneath a ceiling of "
              "cracked\n"
              "stone. A narrow chute rises back toward the shifting "
              "passage.";

  add_link("up", "link_demo_redirect");

  return;
}
