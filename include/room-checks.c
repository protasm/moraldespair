int pre_move(object exit) {
  return 1;
}

void post_move(object exit) {
  object env;

  env = environment(this_player());

  write(env->long());

  return;
}

int pre_action(object action) {
  return 1;
}

void post_action(object action) {
  return;
}
