inherit "/core/object";

string use_word;
object origin;
string destination;

string use_word() {
  return use_word;
}

void set_use_word(string value) {
  use_word = value;
}

object origin() {
  return origin;
}

void set_origin(object value) {
  origin = value;
}

string destination() {
  return destination;
}

void set_destination(string value) {
  destination = value;
}

int use() {
  object env, player;

  player = this_player();

  if (!objectp(player))
    return 0;

  env = environment(player);

  if (!objectp(env))
    return 0;

  if (!env->pre_leave(this_object()))
    return 1;

  player->move(destination);

  env->post_leave(this_object());

  return 1;
}
