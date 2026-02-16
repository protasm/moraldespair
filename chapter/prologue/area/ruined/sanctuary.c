inherit "/core/room/room";

void ensure_watcher();

void create() {
  ::create();

  short_desc = "Sanctuary";
  long_desc = "You stand within the high, vaulted shadows of the Sanctuary. Two centuries ago, this hall was a beacon of hope for die-hard adventurers. Now, the air is cold and tastes of stagnant incense. The glory that once beckoned is long forgotten, replaced by a hollow silence that whispers of a great decay.\n\nYou feel a STRONG urge to... you can't recall?";

  ensure_watcher();
}

void init() {
  ::init();

  ensure_watcher();

  add_action("do_foo", "foo");
  add_action("do_foo2", "foo2");

  return;
}

int do_foo() {
  write("foo!\n");

  return 1;
}

int do_foo2() {
  string line;

  line = "A loose shutter knocks somewhere above, and a cool draft slides "
    + "through the Sanctuary.\n";
  write(line);

  return 1;
}

void ensure_watcher() {
  object watcher;
  object *contents;
  object occupant;
  string occupant_name;
  string occupant_path;
  int i;

  watcher = 0;
  contents = all_inventory(this_object());

  if (pointerp(contents) && sizeof(contents)) {
    for (i = 0; i < sizeof(contents); i++) {
      occupant = contents[i];

      if (!objectp(occupant))
        continue;

      occupant_path = base_name(occupant);

      if (!stringp(occupant_path))
        continue;

      if (occupant_path == "/chapter/prologue/area/ruined/npc/watcher") {
        watcher = occupant;
        break;
      }

      if (!function_exists("is_npc", occupant))
        continue;

      if (!occupant->is_npc())
        continue;

      occupant_name = "";

      if (function_exists("name", occupant))
        occupant_name = occupant->name();

      if (stringp(occupant_name))
        occupant_name = lower_case(trim(occupant_name));

      if (occupant_name != "watcher")
        continue;

      if (function_exists("remove", occupant))
        occupant->remove();
    }
  }

  if (objectp(watcher))
    return;

  watcher = new("/chapter/prologue/area/ruined/npc/watcher");

  if (!objectp(watcher))
    return;

  watcher->move(this_object());

  return;
}
