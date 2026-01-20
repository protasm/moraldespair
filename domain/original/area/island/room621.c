inherit "room/room";

void create() {
  ::create();


  short_desc = "Repair Shop";
  long_desc = "Iron tools lie scattered across heavy stone workbenches, coated in a\n" +
    "thick, undisturbed layer of grit. A large wooden sign hangs crookedly\n" +
    "from the wall, its painted instructions peeling away like dead skin.\n" +
    "The cheerful whistling that once filled the air has been replaced by\n" +
    "a hollow, oppressive silence. To the west, the dim archway leads back\n" +
    "into the cold expanse of the main smeltery.\n";
  dest_dir = ({
    "domain/original/area/island/room620", "west",
  });

  set_light(1);
}
