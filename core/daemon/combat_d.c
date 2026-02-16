/*
 * Master Summary:
 * Purpose:
 *   Implements turn-based combat scheduling and resolution.
 * Approach:
 *   Keeps per-fight runtime state in a daemon-local registry and routes
 *   player-facing combat text through avatar experience events.
 * Dependencies:
 *   - #include "combat_d.h"
 *   - #include <globals.h>
 */

#include "combat_d.h"
#include <globals.h>

mapping active_fights;
mapping fight_for_actor;

void create() {
  active_fights = ([]);
  fight_for_actor = ([]);

  return;
}

int is_valid_combat_target(object attacker, object target) {
  int npc_state;

  if (!objectp(attacker) || !objectp(target))
    return 0;

  if (attacker == target)
    return 0;

  if (!objectp(environment(attacker)) || environment(attacker) != environment(target))
    return 0;

  if (!function_exists("is_npc", target))
    return 0;

  npc_state = target->is_npc();

  if (!intp(npc_state) || !npc_state)
    return 0;

  return 1;
}

string source_name(object actor) {
  string actor_name;

  actor_name = "Someone";

  if (!objectp(actor))
    return actor_name;

  if (function_exists("name", actor))
    actor_name = actor->name();

  if (!stringp(actor_name) || trim(actor_name) == "")
    actor_name = "Someone";

  return trim(actor_name);
}

mapping default_avatar_abilities() {
  return ([
    1 : ([
      "name" : "Punch",
      "cooldown_turns" : 0,
      "min_damage" : 8,
      "max_damage" : 12,
      "player_line" : "You punch %TARGET%."
    ]),
    2 : ([
      "name" : "Kick",
      "cooldown_turns" : 2,
      "min_damage" : 12,
      "max_damage" : 14,
      "player_line" : "You kick hard into %TARGET%'s head."
    ]),
    3 : ([
      "name" : "Charge",
      "cooldown_turns" : 3,
      "min_damage" : 18,
      "max_damage" : 20,
      "player_line" : "You charge forward and slam into %TARGET%."
    ])
  ]);
}

mapping default_npc_abilities() {
  return ([
    1 : ([
      "name" : "Bite",
      "cooldown_turns" : 0,
      "min_damage" : 6,
      "max_damage" : 9,
      "npc_line" : "%ACTOR% lunges and bites."
    ]),
    2 : ([
      "name" : "Tail Slap",
      "cooldown_turns" : 2,
      "min_damage" : 10,
      "max_damage" : 14,
      "npc_line" : "%ACTOR% whips its tail across your side."
    ])
  ]);
}

mapping participant_state_for(object actor) {
  mapping abilities;
  mapping normalized;
  mapping cooldowns;
  mixed *ability_slots;
  mixed raw_slot;
  mixed raw_ability;
  int slot;
  int i;
  int max_hp;
  int speed;

  if (!objectp(actor))
    return 0;

  max_hp = 100;
  speed = 100;

  if (function_exists("combat_max_hp", actor))
    max_hp = actor->combat_max_hp();

  if (!intp(max_hp) || max_hp < 1)
    max_hp = 1;

  if (function_exists("combat_speed", actor))
    speed = actor->combat_speed();

  if (!intp(speed) || speed < 1)
    speed = 1;

  if (speed > 1000)
    speed = 1000;

  abilities = 0;

  if (function_exists("combat_abilities", actor))
    abilities = actor->combat_abilities();

  if (!mapp(abilities)) {
    if (is_connected_avatar(actor))
      abilities = default_avatar_abilities();
    else
      abilities = default_npc_abilities();
  }

  normalized = ([]);
  ability_slots = keys(abilities);

  for (i = 0; i < sizeof(ability_slots); i++) {
    raw_slot = ability_slots[i];

    if (intp(raw_slot))
      slot = raw_slot;
    else if (stringp(raw_slot)) {
      if (sscanf(raw_slot, "%d", slot) != 1)
        slot = 0;
    } else
      slot = 0;

    if (slot < 1 || slot > 4)
      continue;

    raw_ability = abilities[raw_slot];

    if (!mapp(raw_ability))
      continue;

    normalized[slot] = copy(raw_ability);
  }

  if (!mapp(normalized) || !sizeof(normalized)) {
    normalized = ([
      1 : ([
        "name" : "Strike",
        "cooldown_turns" : 0,
        "min_damage" : 1,
        "max_damage" : 3,
        "player_line" : "You strike %TARGET%.",
        "npc_line" : "%ACTOR% strikes."
      ])
    ]);
  }

  if (!mapp(normalized[1])) {
    normalized[1] = ([
      "name" : "Strike",
      "cooldown_turns" : 0,
      "min_damage" : 1,
      "max_damage" : 3,
      "player_line" : "You strike %TARGET%.",
      "npc_line" : "%ACTOR% strikes."
    ]);
  }

  cooldowns = ([]);
  ability_slots = keys(normalized);

  for (i = 0; i < sizeof(ability_slots); i++) {
    if (!intp(ability_slots[i]))
      continue;

    cooldowns[ability_slots[i]] = 0;
  }

  return ([
    "hp" : max_hp,
    "max_hp" : max_hp,
    "speed" : speed,
    "turn_gauge" : 0,
    "cooldowns" : cooldowns,
    "abilities" : normalized,
    "is_player" : is_connected_avatar(actor)
  ]);
}

void register_combat_flags(string fight_id, object actor) {
  if (!stringp(fight_id) || fight_id == "")
    return;

  if (!objectp(actor))
    return;

  fight_for_actor[actor] = fight_id;

  if (function_exists("set_in_combat", actor))
    actor->set_in_combat(1);

  if (function_exists("set_combat_id", actor))
    actor->set_combat_id(fight_id);

  if (function_exists("set_awaiting_combat_input", actor))
    actor->set_awaiting_combat_input(0);

  return;
}

void clear_combat_flags(object actor) {
  if (!objectp(actor))
    return;

  map_delete(fight_for_actor, actor);

  if (function_exists("set_in_combat", actor))
    actor->set_in_combat(0);

  if (function_exists("set_combat_id", actor))
    actor->set_combat_id("");

  if (function_exists("set_awaiting_combat_input", actor))
    actor->set_awaiting_combat_input(0);

  return;
}

void write_combat_event(object avatar, string text, string kind) {
  mapping event;

  if (!is_connected_avatar(avatar))
    return;

  if (!stringp(text) || text == "")
    return;

  if (!stringp(kind) || kind == "")
    kind = "combat.log";

  event = ([
    "type" : "text",
    "source" : "combat",
    "kind" : kind,
    "text" : text
  ]);

  if (function_exists("experience", avatar))
    avatar->experience(event);
  else
    avatar_experience(avatar, text);

  return;
}

object turn_ready_actor(mapping fight) {
  object actor;
  object chosen;
  object *participants;
  mapping state;
  int ready;
  int highest_gauge;
  int i;
  int steps;

  if (!mapp(fight))
    return 0;

  participants = fight["participants"];

  if (!pointerp(participants) || sizeof(participants) < 2)
    return 0;

  for (steps = 0; steps < 1000; steps++) {
    ready = 0;
    chosen = 0;
    highest_gauge = -1;

    for (i = 0; i < sizeof(participants); i++) {
      actor = participants[i];

      if (!objectp(actor))
        continue;

      state = fight["state_by_actor"][actor];

      if (!mapp(state))
        continue;

      if (state["hp"] < 1)
        continue;

      state["turn_gauge"] += state["speed"];

      if (state["turn_gauge"] < 1000)
        continue;

      if (!ready || state["turn_gauge"] > highest_gauge) {
        ready = 1;
        highest_gauge = state["turn_gauge"];
        chosen = actor;
      }
    }

    if (ready)
      return chosen;
  }

  return 0;
}

int tick_actor_cooldowns(mapping state) {
  mapping cooldowns;
  mixed *slots;
  int slot;
  int i;

  if (!mapp(state))
    return 0;

  cooldowns = state["cooldowns"];

  if (!mapp(cooldowns))
    return 0;

  slots = keys(cooldowns);

  for (i = 0; i < sizeof(slots); i++) {
    if (!intp(slots[i]))
      continue;

    slot = slots[i];

    if (!intp(cooldowns[slot]))
      cooldowns[slot] = 0;

    if (cooldowns[slot] > 0)
      cooldowns[slot] -= 1;
  }

  return 1;
}

string format_prompt_line(mapping state) {
  mapping abilities;
  mapping cooldowns;
  mixed *slots;
  string *segments;
  string body;
  string ability_name;
  string left_pad;
  string right_pad;
  int remaining;
  int slot;
  int i;

  if (!mapp(state))
    return "";

  abilities = state["abilities"];
  cooldowns = state["cooldowns"];

  if (!mapp(abilities) || !sizeof(abilities))
    return "";

  slots = sort_array(keys(abilities), 1);
  segments = ({ });

  for (i = 0; i < sizeof(slots); i++) {
    if (!intp(slots[i]))
      continue;

    slot = slots[i];

    if (!mapp(abilities[slot]))
      continue;

    remaining = 0;

    if (mapp(cooldowns) && intp(cooldowns[slot]))
      remaining = cooldowns[slot];

    if (remaining > 0)
      continue;

    ability_name = abilities[slot]["name"];

    if (!stringp(ability_name) || ability_name == "")
      ability_name = "Ability";

    segments += ({ "(" + slot + ") " + upper_case(ability_name) });
  }

  if (!sizeof(segments))
    return "[[[===========NO ACTIONS AVAILABLE===========]]]";

  body = implode(segments, "=====");

  left_pad = "";
  right_pad = "";

  if (sizeof(segments) == 3) {
    left_pad = "=====";
    right_pad = "====";
  } else if (sizeof(segments) == 2) {
    left_pad = "===========";
    right_pad = "===========";
  } else if (sizeof(segments) == 1) {
    left_pad = "==================";
    right_pad = "==================";
  }

  return "[[[" + left_pad + body + right_pad + "]]]";
}

void write_fight_intro(mapping fight) {
  object player;
  object attacker;
  object defender;
  string defender_name;

  if (!mapp(fight))
    return;

  player = fight["player_avatar"];
  attacker = fight["participants"][0];
  defender = fight["participants"][1];

  if (!is_connected_avatar(player))
    return;

  defender_name = source_name(defender);

  write_combat_event(player, defender_name + " rears from the cracked earth!\n\n", "combat.log");

  return;
}

int is_combatant_ready(mapping state) {
  if (!mapp(state))
    return 0;

  if (!intp(state["hp"]))
    return 0;

  if (state["hp"] < 1)
    return 0;

  return 1;
}

int roll_damage(mapping ability) {
  int min_damage;
  int max_damage;
  int range;

  min_damage = 1;
  max_damage = 1;

  if (mapp(ability)) {
    if (intp(ability["min_damage"]))
      min_damage = ability["min_damage"];

    if (intp(ability["max_damage"]))
      max_damage = ability["max_damage"];
  }

  if (min_damage < 0)
    min_damage = 0;

  if (max_damage < min_damage)
    max_damage = min_damage;

  range = max_damage - min_damage;

  if (range < 1)
    return min_damage;

  return min_damage + random(range + 1);
}

string format_action_line(
  mapping fight,
  object actor,
  object target,
  mapping ability
) {
  string actor_name;
  string target_name;
  string template;
  string line;
  mapping actor_state;

  if (!mapp(fight))
    return "";

  actor_name = source_name(actor);
  target_name = source_name(target);
  actor_state = fight["state_by_actor"][actor];

  if (mapp(actor_state) && actor_state["is_player"]) {
    template = "You strike %TARGET%.";

    if (mapp(ability) && stringp(ability["player_line"]))
      template = ability["player_line"];

    line = replace_string(template, "%TARGET%", target_name);

    return line;
  }

  template = "%ACTOR% strikes.";

  if (mapp(ability) && stringp(ability["npc_line"]))
    template = ability["npc_line"];

  if (!stringp(actor_name) || trim(actor_name) == "")
    actor_name = "Someone";

  line = replace_string(template, "%ACTOR%", actor_name);

  if (line == template)
    line = actor_name + " " + template;

  return line;
}

int choose_default_slot(mapping state) {
  mapping abilities;
  mapping cooldowns;
  mixed *slots;
  int slot;
  int i;

  if (!mapp(state))
    return 1;

  abilities = state["abilities"];
  cooldowns = state["cooldowns"];

  if (!mapp(abilities))
    return 1;

  if (mapp(abilities[1])) {
    if (!mapp(cooldowns) || !intp(cooldowns[1]) || cooldowns[1] < 1)
      return 1;
  }

  slots = sort_array(keys(abilities), 1);

  for (i = 0; i < sizeof(slots); i++) {
    if (!intp(slots[i]))
      continue;

    slot = slots[i];

    if (!mapp(cooldowns) || !intp(cooldowns[slot]) || cooldowns[slot] < 1)
      return slot;
  }

  return 1;
}

int choose_npc_slot(mapping fight, object actor) {
  mapping state;
  mapping cooldowns;
  mapping abilities;

  if (!mapp(fight) || !objectp(actor))
    return 1;

  state = fight["state_by_actor"][actor];

  if (!mapp(state))
    return 1;

  cooldowns = state["cooldowns"];
  abilities = state["abilities"];

  if (mapp(abilities[2])) {
    if (!mapp(cooldowns) || !intp(cooldowns[2]) || cooldowns[2] < 1)
      return 2;
  }

  return choose_default_slot(state);
}

int execute_action(string fight_id, object actor, int slot, int timed_out) {
  mapping fight;
  mapping actor_state;
  mapping target_state;
  mapping ability;
  mapping cooldowns;
  mapping abilities;
  object player;
  object target;
  object *participants;
  string line;
  int cooldown_turns;
  int damage;
  int i;

  fight = active_fights[fight_id];

  if (!mapp(fight))
    return 0;

  actor_state = fight["state_by_actor"][actor];

  if (!is_combatant_ready(actor_state))
    return 0;

  participants = fight["participants"];
  target = 0;

  for (i = 0; i < sizeof(participants); i++) {
    if (!objectp(participants[i]) || participants[i] == actor)
      continue;

    target_state = fight["state_by_actor"][participants[i]];

    if (!is_combatant_ready(target_state))
      continue;

    target = participants[i];

    break;
  }

  if (!objectp(target)) {
    finish_fight(fight_id, actor, 0);

    return 0;
  }

  abilities = actor_state["abilities"];
  cooldowns = actor_state["cooldowns"];

  if (!mapp(abilities[slot]))
    slot = choose_default_slot(actor_state);

  ability = abilities[slot];

  if (!mapp(ability))
    return 0;

  if (mapp(cooldowns) && intp(cooldowns[slot]) && cooldowns[slot] > 0)
    return 0;

  damage = roll_damage(ability);

  if (!intp(target_state["hp"]))
    target_state["hp"] = 1;

  target_state["hp"] -= damage;

  if (target_state["hp"] < 0)
    target_state["hp"] = 0;

  line = format_action_line(fight, actor, target, ability);
  line += " [" + target_state["hp"] + "/" + target_state["max_hp"] + "]\n\n";

  player = fight["player_avatar"];
  write_combat_event(player, line, "combat.log");

  cooldown_turns = 0;

  if (intp(ability["cooldown_turns"]))
    cooldown_turns = ability["cooldown_turns"];

  if (cooldown_turns < 0)
    cooldown_turns = 0;

  if (mapp(cooldowns))
    cooldowns[slot] = cooldown_turns;

  actor_state["turn_gauge"] = 0;

  if (target_state["hp"] < 1) {
    finish_fight(fight_id, actor, target);

    return 1;
  }

  return 1;
}

void begin_player_turn(string fight_id, object actor) {
  mapping fight;
  mapping state;
  object player;
  int token;

  fight = active_fights[fight_id];

  if (!mapp(fight))
    return;

  state = fight["state_by_actor"][actor];

  if (!is_combatant_ready(state))
    return;

  player = fight["player_avatar"];
  fight["awaiting_player"] = actor;

  if (function_exists("set_awaiting_combat_input", actor))
    actor->set_awaiting_combat_input(1);

  token = fight["timeout_token"];

  if (!intp(token))
    token = 0;

  token += 1;
  fight["timeout_token"] = token;

  write_combat_event(player, format_prompt_line(state) + "\n", "combat.prompt");
  call_out("player_turn_timeout", 10, fight_id, actor, token);

  return;
}

void begin_npc_turn(string fight_id, object actor) {
  mapping fight;
  mapping state;
  int token;

  fight = active_fights[fight_id];

  if (!mapp(fight) || !fight["active"])
    return;

  state = fight["state_by_actor"][actor];

  if (!is_combatant_ready(state)) {
    finish_fight(fight_id, 0, actor);

    return;
  }

  token = fight["npc_delay_token"];

  if (!intp(token))
    token = 0;

  token += 1;
  fight["npc_delay_token"] = token;
  fight["awaiting_npc"] = actor;

  call_out("npc_turn_timeout", 3, fight_id, actor, token);

  return;
}

void npc_turn_timeout(string fight_id, object actor, int delay_token) {
  mapping fight;
  mapping state;
  int slot;

  fight = active_fights[fight_id];

  if (!mapp(fight) || !fight["active"])
    return;

  if (fight["awaiting_npc"] != actor)
    return;

  if (!intp(fight["npc_delay_token"]) || fight["npc_delay_token"] != delay_token)
    return;

  state = fight["state_by_actor"][actor];

  if (!is_combatant_ready(state)) {
    finish_fight(fight_id, 0, actor);

    return;
  }

  fight["awaiting_npc"] = 0;
  slot = choose_npc_slot(fight, actor);

  if (!execute_action(fight_id, actor, slot, 0)) {
    finish_fight(fight_id, 0, actor);

    return;
  }

  process_fight(fight_id);

  return;
}

void player_turn_timeout(string fight_id, object actor, int timeout_token) {
  mapping fight;
  mapping state;
  int slot;

  fight = active_fights[fight_id];

  if (!mapp(fight) || !fight["active"])
    return;

  if (fight["awaiting_player"] != actor)
    return;

  if (!intp(fight["timeout_token"]) || fight["timeout_token"] != timeout_token)
    return;

  state = fight["state_by_actor"][actor];

  if (!is_combatant_ready(state)) {
    finish_fight(fight_id, 0, actor);

    return;
  }

  slot = choose_default_slot(state);
  fight["awaiting_player"] = 0;

  if (function_exists("set_awaiting_combat_input", actor))
    actor->set_awaiting_combat_input(0);

  if (!execute_action(fight_id, actor, slot, 1))
    return;

  process_fight(fight_id);

  return;
}

void finish_fight(string fight_id, object winner, object loser) {
  mapping fight;
  mapping winner_state;
  object player;
  object *participants;
  int i;

  fight = active_fights[fight_id];

  if (!mapp(fight))
    return;

  fight["active"] = 0;
  player = fight["player_avatar"];
  participants = fight["participants"];

  for (i = 0; i < sizeof(participants); i++)
    clear_combat_flags(participants[i]);

  if (objectp(winner) && mapp(fight["state_by_actor"][winner])) {
    winner_state = fight["state_by_actor"][winner];

    if (winner_state["is_player"] && objectp(loser)) {
      write_combat_event(player, source_name(loser) + " collapses.\n", "combat.result");
      write_combat_event(player, "\nVICTORY!\n", "combat.result");
    } else if (is_connected_avatar(player))
      write_combat_event(player, "\nDEFEAT!\n", "combat.result");
  }

  map_delete(active_fights, fight_id);

  return;
}

void process_fight(string fight_id) {
  mapping fight;
  mapping state;
  object actor;

  fight = active_fights[fight_id];

  if (!mapp(fight) || !fight["active"])
    return;

  if (fight["resolving"])
    return;

  fight["resolving"] = 1;

  while (fight["active"]) {
    actor = turn_ready_actor(fight);

    if (!objectp(actor)) {
      finish_fight(fight_id, 0, 0);

      break;
    }

    state = fight["state_by_actor"][actor];

    if (!is_combatant_ready(state)) {
      finish_fight(fight_id, 0, actor);

      break;
    }

    tick_actor_cooldowns(state);

    if (state["is_player"]) {
      begin_player_turn(fight_id, actor);

      break;
    }

    begin_npc_turn(fight_id, actor);

    break;
  }

  fight = active_fights[fight_id];

  if (mapp(fight))
    fight["resolving"] = 0;

  return;
}

int start_fight(object attacker, object defender) {
  mapping fight;
  mapping state_by_actor;
  string fight_id;

  if (!is_valid_combat_target(attacker, defender))
    return 0;

  if (stringp(fight_for_actor[attacker]) && fight_for_actor[attacker] != "")
    return 0;

  if (stringp(fight_for_actor[defender]) && fight_for_actor[defender] != "")
    return 0;

  fight_id = "fight-" + time() + "-" + random(1000000);
  state_by_actor = ([]);

  state_by_actor[attacker] = participant_state_for(attacker);
  state_by_actor[defender] = participant_state_for(defender);

  fight = ([
    "id" : fight_id,
    "active" : 1,
    "resolving" : 0,
    "participants" : ({ attacker, defender }),
    "state_by_actor" : state_by_actor,
    "player_avatar" : attacker,
    "room" : environment(attacker),
    "awaiting_player" : 0,
    "timeout_token" : 0,
    "awaiting_npc" : 0,
    "npc_delay_token" : 0
  ]);

  active_fights[fight_id] = fight;
  register_combat_flags(fight_id, attacker);
  register_combat_flags(fight_id, defender);
  write_fight_intro(fight);
  process_fight(fight_id);

  return 1;
}

int handle_input(object avatar, string raw) {
  mapping fight;
  mapping state;
  string fight_id;
  int slot;

  if (!is_connected_avatar(avatar))
    return 0;

  fight_id = fight_for_actor[avatar];

  if (!stringp(fight_id) || fight_id == "")
    return 0;

  fight = active_fights[fight_id];

  if (!mapp(fight) || !fight["active"])
    return 0;

  if (fight["awaiting_player"] != avatar)
    return 1;

  if (!stringp(raw))
    raw = "";

  raw = trim(raw);
  if (sscanf(raw, "%d", slot) != 1)
    slot = 0;
  state = fight["state_by_actor"][avatar];

  if (!intp(slot) || slot < 1 || slot > 4 || !mapp(state["abilities"][slot])) {
    write_combat_event(
      avatar,
      "Choose an available combat ability by number (1-4).\n",
      "combat.prompt"
    );
    write_combat_event(avatar, format_prompt_line(state) + "\n", "combat.prompt");

    return 1;
  }

  if (mapp(state["cooldowns"]) && intp(state["cooldowns"][slot])
    && state["cooldowns"][slot] > 0) {
    write_combat_event(avatar, "That ability is on cooldown.\n", "combat.prompt");
    write_combat_event(avatar, format_prompt_line(state) + "\n", "combat.prompt");

    return 1;
  }

  fight["awaiting_player"] = 0;

  if (function_exists("set_awaiting_combat_input", avatar))
    avatar->set_awaiting_combat_input(0);

  if (!execute_action(fight_id, avatar, slot, 0))
    return 1;

  process_fight(fight_id);

  return 1;
}
