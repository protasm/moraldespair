inherit "/core/command";

void render_exits(object player, mapping exits);

void create() {
  ::create();

  set_category("General");
  set_help_text(
    "Usage: look or look <target>\n"
    "Show the description of your current location.\n"
    "You can also look at a specific target to inspect it.\n"
  );
}

int main(string arg) {
  object player, room;
  string short_desc, long_desc;
  mapping exits;

  player = this_player();
  room = environment(player);

  if (!objectp(room)) {
    write("You are nowhere.\n");

    return 1;
  }

  /* Short */
  short_desc = room->short();

  if (stringp(short_desc) && short_desc != "")
    write(short_desc + "\n");

  /* Long */
  long_desc = room->long();

  if (stringp(long_desc) && long_desc != "")
    write(long_desc + "\n");

  /* Exits */
  exits = LINK_D->links_by_direction_for_room(base_name(room));

  render_exits(player, exits);

  return 1;
}

void render_exits(object player, mapping exits) {
  string *dirs;

  if (!mapp(exits) || !sizeof(exits)) {
    write("There are no obvious exits.\n");

    return;
  }

  dirs = sort_array(keys(exits), 1);

  write( "Obvious exits: " + implode(dirs, ", ") + ".\n");
}
