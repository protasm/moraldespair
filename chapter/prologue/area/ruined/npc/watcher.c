inherit "/core/npc/npc";

int next_fidget_at;

void emit_fidget();
void schedule_next_fidget();

void create() {
  ::create();

  set_name("Watcher");
  set_short("Watcher");
  set_long(
    "A gaunt figure wrapped in threadbare cloth stands beneath a cracked "
    + "archway. Its posture never shifts, and a pale mask hides whatever "
    + "face remains.\n"
  );
  add_id("watcher");
  add_id("figure");
  add_id("mask");

  next_fidget_at = 0;
  set_heart_beat(1);
  schedule_next_fidget();
}

void heart_beat() {
  ::heart_beat();

  if (time() < next_fidget_at)
    return;

  emit_fidget();
  schedule_next_fidget();

  return;
}

void schedule_next_fidget() {
  next_fidget_at = time() + 30 + random(31);

  return;
}

void emit_fidget() {
  object env;
  object *contents;
  object listener;
  object controller;
  string line;
  int i;

  env = environment(this_object());

  if (!objectp(env))
    return;

  contents = all_inventory(env);

  if (!pointerp(contents) || !sizeof(contents))
    return;

  if (random(2))
    line = "Watcher shifts its weight, cloth whispering across old stone.\n";
  else
    line = "Watcher tilts its masked face toward the broken arches, then "
      + "stills.\n";

  for (i = 0; i < sizeof(contents); i++) {
    listener = contents[i];

    if (!objectp(listener) || listener == this_object())
      continue;

    if (!function_exists("player", listener))
      continue;

    controller = listener->player();

    if (!objectp(controller) || !userp(controller))
      continue;

    if (!function_exists("experience", listener))
      continue;

    listener->experience(([ "type" : "text", "text" : line ]));
  }

  return;
}
