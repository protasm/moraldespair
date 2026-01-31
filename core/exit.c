inherit "/core/object"

string use_word;
string destination;

string use_word() {
  return use_word;
}

string set_use_word(string value) {
  use_word = value;
}

string destination() {
  return destination;
}

string set_destination(string value) {
  destination = value;
}

void use() {
  object env;

  env = environment(this_player());

  if (!ienv->pre_move(this_object())
    return;

  move(destination);

  env->post_move(this_object());
}
