inherit "/core/exit";

int door_closed;

void create() {
  ::create();

  door_closed = 0;
}

void set_closed(int value) {
  door_closed = value;
}

int pre_leave(object exit) {
  if (door_closed) {
    tell_object(this_player(), "The eastern door is closed.\n");

    return 0;
  }

  return 1;
}
