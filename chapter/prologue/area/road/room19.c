inherit "/core/room/room";

void create() {
  ::create();

  short_desc = "Road Test";
  long_desc = "A weathered stretch of road lies under settled dust and split "
              "stone. This section has been marked for concrete-room testing, "
              "and the silence remains unbroken.\n";

  return;
}

void init() {
  ::init();

  add_action("do_test", "test");

  return;
}

int do_test(string args) {
  write("Test action executed in Road Test.\n");

  return 1;
}
