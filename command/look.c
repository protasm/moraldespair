inherit "/core/command";

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
  object player;
  object env;
  object link;
  mapping exits;
  mapping direction_aliases;
  string target;
  string description;

  player = this_player();

  if (!objectp(player))
    return 0;

  if (!stringp(arg))
    arg = "";

  target = lower_case(trim(arg));

  if (target != "") {
    direction_aliases = ([
      "n" : "north",
      "s" : "south",
      "e" : "east",
      "w" : "west",
      "ne" : "northeast",
      "nw" : "northwest",
      "se" : "southeast",
      "sw" : "southwest",
      "u" : "up",
      "d" : "down"
    ]);

    if (mapp(direction_aliases) && stringp(direction_aliases[target]))
      target = direction_aliases[target];

    env = environment(player);

    if (objectp(env)) {
      exits = LINK_D->links_by_direction_for_room(base_name(env));

      if (mapp(exits) && objectp(exits[target]))
        link = exits[target];

      if (objectp(link)) {
        if (function_exists("describe_from_endpoint", link))
          description = link->describe_from_endpoint(base_name(env));
        else if (function_exists("query_appearance", link))
          description = link->query_appearance(base_name(env));

        if (!stringp(description) || description == "")
          description = "It seems possible to go that way.\n";

        write(description);

        return 1;
      }
    }

    write("You don't see that here.\n");

    return 1;
  }

  if (function_exists("show_location", player)) {
    player->show_location(1, 1);

    return 1;
  }

  write("You are nowhere.\n");

  return 1;
}
