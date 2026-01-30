int clean_up(int inherited) {
  write("apply clean_up called in object.c\n");

  return 0;
}

varargs void create(mixed args...) {
  write("apply create called in object.c\n");

  return;
}

void heart_beat() {
  write("apply heart_beat called in object.c\n");

  return;
}

int id(string an_id) {
  write("apply id called in object.c\n");

  return 0;
}

void init() {
  write("apply init called in object.c\n");

  return;
}

int is_living() {
  write("apply is_living called in object.c\n");

  return 0;
}

void move_or_destruct(object dest) {
  write("apply move_or_destruct called in object.c\n");

  return;
}

void on_destruct() {
  write("apply on_destruct called in object.c\n");

  return;
}

void reset() {
  write("apply reset called in object.c\n");

  return;
}

void virtual_start() {
  write("apply virtual_start called in object.c\n");

  return;
}
