inherit "/core/object";

string use_word;
string destination;

string use_word() {
  return use_word;
}

string set_use_word(string value) {
  use_word = value;

  return use_word;
}

string destination() {
  return destination;
}

string set_destination(string value) {
  destination = value;

  return destination;
}

void use() {
  object env, new_env, player;
  string target;

  player = this_player();

  if (!objectp(player))
    return;

  env = environment(player);

  if (objectp(env)) {
    if (!env->pre_move(this_object()))
      return;
  }

  target = destination;

  if (stringp(target) && target[0] != '/')
    target = "/" + target;

  player->move(target);

  new_env = environment(player);

  if (objectp(new_env))
    new_env->post_move(this_object());

  return;
}
