int clean_up(int inherited) {
  write("OBJECT:clean_up()\n");

  return 0;
}

varargs void create(mixed args...) {
  write("OBJECT:create()\n");

  return;
}

void heart_beat() {
  write("OBJECT:heart_beat()\n");

  return;
}

int id(string an_id) {
  write("OBJECT:id()\n");

  return 0;
}

void init() {
  write("OBJECT:init()\n");

  return;
}

int is_living() {
  write("OBJECT:is_living()\n");

  return 0;
}

void move_or_destruct(object dest) {
  write("OBJECT:move_or_destruct()\n");

  return;
}

void on_destruct() {
  write("OBJECT:destruct()\n");

  return;
}

void reset() {
  write("OBJECT:reset()\n");

  return;
}

void virtual_start() {
  write("OBJECT:virtual_start()\n");

  return;
}
