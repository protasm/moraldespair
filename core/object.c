int move(mixed dest) {
  // add code here to prevent disallowed moves (target is full, object
  // is immovable, etc.).
  move_object(dest);

  return 1;
}

void remove() {
  // add code here to prevent unwanted destructions.
  // update attributes of the container and the containees.
  destruct(this_object());
}

int clean_up(int inherited) {
  destruct(this_object());

  return 0;
}

varargs void create(mixed args...) {
  return;
}

void heart_beat() {
  return;
}

int id(string an_id) {
  return 0;
}

void init() {
  return;
}

int is_living() {
  return 0;
}

void move_or_destruct(object dest) {
  return;
}

void on_destruct() {
  return;
}

void reset() {
  return;
}

void virtual_start() {
  return;
}
