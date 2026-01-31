inherit "/core/object";

#include <exit-checks.c>

string use_word;
object origin;
string destination;
function pre_leave_hook;
function post_leave_hook;
function pre_arrive_hook;
function post_arrive_hook;

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

string opposite_dir(string direction) {
  mapping opposites;

  opposites = ([
    "north" : "south",
    "south" : "north",
    "east" : "west",
    "west" : "east",
    "northeast" : "southwest",
    "southwest" : "northeast",
    "northwest" : "southeast",
    "southeast" : "northwest",
    "up" : "down",
    "down" : "up"
  ]);

  return opposites[direction];
}

void set_pre_leave(function func) {
  pre_leave_hook = func;
}

void set_post_leave(function func) {
  post_leave_hook = func;
}

void set_pre_arrive(function func) {
  pre_arrive_hook = func;
}

void set_post_arrive(function func) {
  post_arrive_hook = func;
}

int run_pre_leave(object exit) {
  if (functionp(pre_leave_hook)) {
    if (!evaluate(pre_leave_hook, exit))
      return 0;
  }

  return pre_leave(exit);
}

void run_post_leave(object exit) {
  if (functionp(post_leave_hook))
    evaluate(post_leave_hook, exit);

  post_leave(exit);
}

int run_pre_arrive(object exit) {
  if (functionp(pre_arrive_hook)) {
    if (!evaluate(pre_arrive_hook, exit))
      return 0;
  }

  return pre_arrive(exit);
}

void run_post_arrive(object exit) {
  if (functionp(post_arrive_hook))
    evaluate(post_arrive_hook, exit);

  post_arrive(exit);
}

int use() {
  object env, player, dest_room, dest_exit;
  string dest_entry;

  player = this_player();

  if (!objectp(player))
    return 0;

  env = environment(player);

  if (!objectp(env))
    return 0;

  if (!env->pre_leave(this_object()))
    return 1;

  if (!run_pre_leave(this_object()))
    return 1;

  dest_room = load_object(destination);

  if (objectp(dest_room)) {
    dest_entry = opposite_dir(use_word);

    if (stringp(dest_entry) && function_exists("exit_for", dest_room))
      dest_exit = dest_room->exit_for(dest_entry);

    if (objectp(dest_exit))
      if (!dest_exit->run_pre_arrive(this_object()))
        return 1;

    if (function_exists("pre_arrive", dest_room)) {
      if (!dest_room->pre_arrive(this_object()))
        return 1;
    }
  }

  player->move(destination);

  run_post_leave(this_object());

  env->post_leave(this_object());

  if (objectp(dest_room)) {
    if (objectp(dest_exit))
      dest_exit->run_post_arrive(this_object());

    if (function_exists("post_arrive", dest_room))
      dest_room->post_arrive(this_object());
  }

  return 1;
}
