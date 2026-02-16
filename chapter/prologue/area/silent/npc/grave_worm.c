inherit "/core/npc/npc";

mapping movement_event_payload(
  string phase,
  string direction,
  string actor_name,
  object room
) {
  string phrase;
  string cue;

  if (!stringp(phase))
    phase = "departure";

  if (!stringp(direction) || direction == "")
    direction = "away";

  if (!stringp(actor_name) || actor_name == "")
    actor_name = "Grave Worm";

  cue = "with a wet, squelching sound.";

  if (phase == "arrival")
    phrase = "arrives from " + direction;
  else
    phrase = "leaves " + direction;

  return ([
    "visible_line" : actor_name + " " + phrase + ".",
    "audible_line" : "A wet, squelching sound shifts " + direction + ".",
    "both_line" : actor_name + " " + phrase + " " + cue,
    "audio_cue" : cue,
    "anonymous_name" : "Something"
  ]);
}

void create() {
  ::create();

  set_name("Grave Worm");
  set_short("Grave Worm");
  set_long(
    "A pale worm the length of a forearm drags itself through damp grit, "
    + "its ringed hide caked with black soil and grave dust. It pauses at "
    + "times, then folds forward again in slow, blind pulls.\n"
  );

  add_id("grave worm");
  add_id("worm");
  add_id("grave");

  set_level(1);
  set_combat_speed(125);
  set_combat_max_hp(90);
  set_combat_abilities(([
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
  ]));
  set_fidget_texts(({
    "Grave Worm curls and uncurls in the damp grit.",
    "Grave Worm presses into the soil, then drags forward a handspan.",
    "Grave Worm leaves a wet trail across the cracked stone."
  }));
  set_mobility_delay_range(30, 60);
  set_mobility_move_chance(50);
  set_path_memory_max(2);
  set_mobility_enabled(1);

  return;
}
