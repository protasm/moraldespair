/*
 * Master Summary:
 * Purpose:
 *   Implements the object behavior defined in core/daemon/experience_d.c.
 * Approach:
 *   Centralizes modality definitions, sensory evaluation, and observer
 *   delivery so experience emission stays consistent across systems.
 * Dependencies:
 *   - #include "/core/daemon/experience_d.h"
 */

#include "/core/daemon/experience_d.h"

mapping modalities;
mapping form_sensor_defaults;
string *modality_sort_order;

/* Method Summary:
 * Purpose:
 *   Handles create for this object.
 * Parameters:
 *   - none
 * Approach:
 *   Initializes the core modality registry and default form sensors.
 * Side effects:
 *   Stores daemon-level definitions for modality and form lookups.
 * Returns:
 *   void result from create.
 */
void create() {
  modalities = ([
    "vision" : ([ "label" : "visual" ]),
    "audio" : ([ "label" : "auditory" ]),
    "smell" : ([ "label" : "olfactory" ]),
    "touch" : ([ "label" : "tactile" ]),
    "taste" : ([ "label" : "gustatory" ])
  ]);

  form_sensor_defaults = ([
    "humanoid" : ([
      "vision" : ([ "sensitivity" : 2, "low_light" : 0 ]),
      "audio" : ([ "sensitivity" : 2 ]),
      "smell" : ([ "sensitivity" : 1 ]),
      "touch" : ([ "sensitivity" : 1 ]),
      "taste" : ([ "sensitivity" : 1 ])
    ]),
    "fish" : ([
      "vision" : ([ "sensitivity" : 1, "low_light" : 1 ]),
      "audio" : ([ "sensitivity" : 2 ]),
      "smell" : ([ "sensitivity" : 2 ]),
      "touch" : ([ "sensitivity" : 2 ]),
      "taste" : ([ "sensitivity" : 2 ])
    ]),
    "dragon" : ([
      "vision" : ([ "sensitivity" : 3, "low_light" : 2 ]),
      "audio" : ([ "sensitivity" : 3 ]),
      "smell" : ([ "sensitivity" : 3 ]),
      "touch" : ([ "sensitivity" : 2 ]),
      "taste" : ([ "sensitivity" : 2 ])
    ])
  ]);
  modality_sort_order = ({ "vision", "audio", "smell", "touch", "taste" });

  return;
}

/* Method Summary:
 * Purpose:
 *   Handles unique_modalities for this object.
 * Parameters:
 *   - string *modalities
 * Approach:
 *   Deduplicates and normalizes detected modality keys.
 * Side effects:
 *   None.
 * Returns:
 *   string result from unique_modalities.
 */
string *unique_modalities(string *modalities) {
  string *unique;
  string modality;
  int i;

  unique = ({ });

  if (!pointerp(modalities))
    return unique;

  for (i = 0; i < sizeof(modalities); i++) {
    modality = modalities[i];

    if (!stringp(modality) || modality == "")
      continue;

    if (member_array(modality, unique) != -1)
      continue;

    unique += ({ modality });
  }

  return unique;
}

/* Method Summary:
 * Purpose:
 *   Handles modality_combo_key for this object.
 * Parameters:
 *   - string *modalities
 * Approach:
 *   Produces stable modality-combination keys for synthesis lookups.
 * Side effects:
 *   None.
 * Returns:
 *   string result from modality_combo_key.
 */
string modality_combo_key(string *modalities) {
  string *ordered;
  string modality;
  int i;

  ordered = ({ });
  modalities = unique_modalities(modalities);

  if (!pointerp(modality_sort_order) || !sizeof(modality_sort_order))
    modality_sort_order = ({ "vision", "audio", "smell", "touch", "taste" });

  for (i = 0; i < sizeof(modality_sort_order); i++) {
    modality = modality_sort_order[i];

    if (member_array(modality, modalities) != -1)
      ordered += ({ modality });
  }

  for (i = 0; i < sizeof(modalities); i++) {
    modality = modalities[i];

    if (member_array(modality, ordered) == -1)
      ordered += ({ modality });
  }

  if (!sizeof(ordered))
    return "";

  return implode(ordered, "+");
}

/* Method Summary:
 * Purpose:
 *   Handles actor_name_for_event for this object.
 * Parameters:
 *   - object actor
 * Approach:
 *   Resolves stable actor display text for event payload formatting.
 * Side effects:
 *   None.
 * Returns:
 *   string result from actor_name_for_event.
 */
string actor_name_for_event(object actor) {
  string actor_name;

  actor_name = "Someone";

  if (!objectp(actor))
    return actor_name;

  if (function_exists("name", actor))
    actor_name = actor->name();

  if (!stringp(actor_name) || actor_name == "")
    actor_name = "Someone";

  return actor_name;
}

/* Method Summary:
 * Purpose:
 *   Handles modality_registry for this object.
 * Parameters:
 *   - none
 * Approach:
 *   Exposes modality definition metadata for callers.
 * Side effects:
 *   None.
 * Returns:
 *   mapping result from modality_registry.
 */
mapping modality_registry() {
  if (!mapp(modalities))
    return ([ ]);

  return copy(modalities);
}

/* Method Summary:
 * Purpose:
 *   Handles supported_modalities for this object.
 * Parameters:
 *   - none
 * Approach:
 *   Returns normalized modality keys in arbitrary mapping order.
 * Side effects:
 *   None.
 * Returns:
 *   string result from supported_modalities.
 */
string *supported_modalities() {
  if (!mapp(modalities))
    return ({ });

  return keys(modalities);
}

/* Method Summary:
 * Purpose:
 *   Handles modality_is_valid for this object.
 * Parameters:
 *   - string modality
 * Approach:
 *   Validates that modality text maps to a registered modality.
 * Side effects:
 *   None.
 * Returns:
 *   int result from modality_is_valid.
 */
int modality_is_valid(string modality) {
  string normalized;

  if (!stringp(modality))
    return 0;

  normalized = lower_case(trim(modality));

  if (normalized == "")
    return 0;

  if (!mapp(modalities))
    return 0;

  return mapp(modalities[normalized]);
}

/* Method Summary:
 * Purpose:
 *   Handles is_valid_form for this object.
 * Parameters:
 *   - string form
 * Approach:
 *   Validates that the requested sensory form has default support.
 * Side effects:
 *   None.
 * Returns:
 *   int result from is_valid_form.
 */
int is_valid_form(string form) {
  string normalized;

  if (!stringp(form))
    return 0;

  normalized = lower_case(trim(form));

  if (normalized == "")
    return 0;

  if (!mapp(form_sensor_defaults))
    return 0;

  return mapp(form_sensor_defaults[normalized]);
}

/* Method Summary:
 * Purpose:
 *   Handles default_sensor_profile_for_form for this object.
 * Parameters:
 *   - string form
 * Approach:
 *   Returns immutable baseline sensor thresholds for the requested form.
 * Side effects:
 *   None.
 * Returns:
 *   mapping result from default_sensor_profile_for_form.
 */
mapping default_sensor_profile_for_form(string form) {
  string normalized;
  mapping profile;

  if (!stringp(form) || form == "")
    normalized = "humanoid";
  else
    normalized = lower_case(trim(form));

  if (!mapp(form_sensor_defaults))
    return ([ ]);

  profile = form_sensor_defaults[normalized];

  if (!mapp(profile))
    profile = form_sensor_defaults["humanoid"];

  if (!mapp(profile))
    return ([ ]);

  return copy(profile);
}

/* Method Summary:
 * Purpose:
 *   Handles merge_sensor_profiles for this object.
 * Parameters:
 *   - mapping base_profile, mapping override_profile
 * Approach:
 *   Merges modality-level sensor maps while preserving base defaults.
 * Side effects:
 *   None.
 * Returns:
 *   mapping result from merge_sensor_profiles.
 */
mapping merge_sensor_profiles(mapping base_profile, mapping override_profile) {
  mapping merged;
  string *modality_keys;
  string modality;
  mixed override_value;
  int i;

  merged = ([ ]);

  if (mapp(base_profile))
    merged = copy(base_profile);

  if (!mapp(override_profile))
    return merged;

  modality_keys = keys(override_profile);

  if (!pointerp(modality_keys) || !sizeof(modality_keys))
    return merged;

  for (i = 0; i < sizeof(modality_keys); i++) {
    modality = modality_keys[i];
    override_value = override_profile[modality];

    if (!stringp(modality) || modality == "")
      continue;

    if (!modality_is_valid(modality))
      continue;

    if (!mapp(override_value))
      continue;

    merged[modality] = copy(override_value);
  }

  return merged;
}

/* Method Summary:
 * Purpose:
 *   Handles object_sensory_form for this object.
 * Parameters:
 *   - object observer
 * Approach:
 *   Resolves the observer form through its exposed sensory API.
 * Side effects:
 *   None.
 * Returns:
 *   string result from object_sensory_form.
 */
string object_sensory_form(object observer) {
  string form;

  if (!objectp(observer))
    return "humanoid";

  if (function_exists("sensory_form", observer))
    form = observer->sensory_form();

  if (!stringp(form) || form == "")
    return "humanoid";

  form = lower_case(trim(form));

  if (!is_valid_form(form))
    return "humanoid";

  return form;
}

/* Method Summary:
 * Purpose:
 *   Handles object_sensor_profile for this object.
 * Parameters:
 *   - object observer
 * Approach:
 *   Combines form defaults with optional per-object sensor overrides.
 * Side effects:
 *   None.
 * Returns:
 *   mapping result from object_sensor_profile.
 */
mapping object_sensor_profile(object observer) {
  string form;
  mapping default_profile;
  mapping override_profile;

  if (!objectp(observer))
    return ([ ]);

  form = object_sensory_form(observer);
  default_profile = default_sensor_profile_for_form(form);

  override_profile = 0;

  if (function_exists("sensory_profile", observer))
    override_profile = observer->sensory_profile();

  if (!mapp(override_profile))
    return default_profile;

  return merge_sensor_profiles(default_profile, override_profile);
}

/* Method Summary:
 * Purpose:
 *   Handles object_can_perceive_facet for this object.
 * Parameters:
 *   - object observer, mapping facet
 * Approach:
 *   Evaluates modality-specific thresholds against observer sensors.
 * Side effects:
 *   None.
 * Returns:
 *   int result from object_can_perceive_facet.
 */
int object_can_perceive_facet(object observer, mapping facet) {
  mapping profile;
  mapping sensor;
  string modality;
  int required_sense;
  int sensitivity;
  int required_light;
  int ambient_light;
  int low_light_bonus;
  int effective_light;

  if (!objectp(observer))
    return 0;

  if (!mapp(facet))
    return 0;

  modality = facet["modality"];

  if (!modality_is_valid(modality))
    return 0;

  profile = object_sensor_profile(observer);

  if (!mapp(profile))
    return 0;

  sensor = profile[modality];

  if (!mapp(sensor))
    return 0;

  required_sense = facet["min_sense"];

  if (!intp(required_sense))
    required_sense = 1;

  sensitivity = sensor["sensitivity"];

  if (!intp(sensitivity))
    sensitivity = 0;

  if (sensitivity < required_sense)
    return 0;

  if (modality != "vision")
    return 1;

  required_light = facet["min_light"];

  if (!intp(required_light))
    required_light = 0;

  ambient_light = facet["ambient_light"];

  if (!intp(ambient_light))
    ambient_light = 1;

  low_light_bonus = sensor["low_light"];

  if (!intp(low_light_bonus))
    low_light_bonus = 0;

  effective_light = ambient_light + low_light_bonus;

  if (effective_light < required_light)
    return 0;

  return 1;
}

/* Method Summary:
 * Purpose:
 *   Handles event_is_valid for this object.
 * Parameters:
 *   - mapping event
 * Approach:
 *   Ensures events provide one or more valid modality facets.
 * Side effects:
 *   None.
 * Returns:
 *   int result from event_is_valid.
 */
int event_is_valid(mapping event) {
  mapping facet;
  string modality;
  mixed facets;
  int i;

  if (!mapp(event))
    return 0;

  facets = event["facets"];

  if (!pointerp(facets) || !sizeof(facets))
    return 0;

  for (i = 0; i < sizeof(facets); i++) {
    facet = facets[i];

    if (!mapp(facet))
      continue;

    modality = facet["modality"];

    if (modality_is_valid(modality))
      return 1;
  }

  return 0;
}

/* Method Summary:
 * Purpose:
 *   Handles perceive_event for this object.
 * Parameters:
 *   - object observer, mapping event
 * Approach:
 *   Filters event facets against observer sensors and emits a viewer-specific
 *   event payload only when at least one facet is detected.
 * Side effects:
 *   None.
 * Returns:
 *   mapping result from perceive_event.
 */
mapping perceive_event(object observer, mapping event) {
  mapping perceived;
  mapping synthesis;
  mapping facet;
  string text;
  string synthesis_key;
  string synthesis_text;
  string *lines;
  string *detected_modalities;
  mixed facets;
  int i;

  if (!objectp(observer))
    return 0;

  if (!event_is_valid(event))
    return 0;

  facets = event["facets"];
  lines = ({ });
  detected_modalities = ({ });

  for (i = 0; i < sizeof(facets); i++) {
    facet = facets[i];

    if (!mapp(facet))
      continue;

    if (!object_can_perceive_facet(observer, facet))
      continue;

    text = facet["text"];

    if (stringp(text) && text != "")
      lines += ({ text });

    if (stringp(facet["modality"]))
      detected_modalities += ({ facet["modality"] });
  }

  if (!sizeof(lines))
    return 0;

  detected_modalities = unique_modalities(detected_modalities);
  synthesis = event["synthesis"];

  if (mapp(synthesis)) {
    synthesis_key = modality_combo_key(detected_modalities);

    if (synthesis_key != "")
      synthesis_text = synthesis[synthesis_key];

    if (!stringp(synthesis_text) || synthesis_text == "")
      synthesis_text = synthesis["default"];

    if (stringp(synthesis_text) && synthesis_text != "")
      lines = ({ ensure_line_break(synthesis_text) });
  }

  perceived = ([
    "type" : "experience",
    "kind" : event["kind"],
    "source" : event["source"],
    "text" : implode(lines, ""),
    "modalities" : detected_modalities,
    "origin" : event["origin"],
    "destination" : event["destination"],
    "actor" : event["actor"]
  ]);

  return perceived;
}

/* Method Summary:
 * Purpose:
 *   Handles room_light_level for this object.
 * Parameters:
 *   - object room
 * Approach:
 *   Resolves a conservative ambient light level from room APIs.
 * Side effects:
 *   None.
 * Returns:
 *   int result from room_light_level.
 */
int room_light_level(object room) {
  int level;

  if (!objectp(room))
    return 1;

  level = 1;

  if (function_exists("query_light_level", room))
    level = room->query_light_level();
  else if (function_exists("query_light", room))
    level = room->query_light();

  if (!intp(level))
    level = 1;

  return level;
}

/* Method Summary:
 * Purpose:
 *   Handles route_event_to_observer for this object.
 * Parameters:
 *   - object observer, mapping event
 * Approach:
 *   Executes sensory filtering then pushes the resulting event into the
 *   observer's local experience ingress.
 * Side effects:
 *   May call observer->experience(...) with perceived event data.
 * Returns:
 *   int result from route_event_to_observer.
 */
int route_event_to_observer(object observer, mapping event) {
  mapping perceived;

  if (!objectp(observer))
    return 0;

  if (!function_exists("experience", observer))
    return 0;

  perceived = perceive_event(observer, event);

  if (!mapp(perceived))
    return 0;

  observer->experience(perceived);

  return 1;
}

/* Method Summary:
 * Purpose:
 *   Handles emit_room_event for this object.
 * Parameters:
 *   - object actor, object room, mapping event
 * Approach:
 *   Broadcasts one event to all observer objects in a room except the actor.
 * Side effects:
 *   Routes filtered event payloads through observer experience handlers.
 * Returns:
 *   void result from emit_room_event.
 */
void emit_room_event(object actor, object room, mapping event) {
  object *listeners;
  object listener;
  int i;

  if (!objectp(room))
    return;

  if (!event_is_valid(event))
    return;

  listeners = all_inventory(room);

  if (!pointerp(listeners) || !sizeof(listeners))
    return;

  for (i = 0; i < sizeof(listeners); i++) {
    listener = listeners[i];

    if (!objectp(listener) || listener == actor)
      continue;

    if (!function_exists("experience", listener))
      continue;

    route_event_to_observer(listener, event);
  }

  return;
}

/* Method Summary:
 * Purpose:
 *   Handles emit_speech_event for this object.
 * Parameters:
 *   - object actor, object room, string spoken_text
 * Approach:
 *   Emits one canonical speech event with audio and visual facets.
 * Side effects:
 *   Routes observer-specific perceived speech into experience ingress.
 * Returns:
 *   void result from emit_speech_event.
 */
void emit_speech_event(object actor, object room, string spoken_text) {
  mapping event;
  string actor_name;
  string line;
  int ambient_light;

  if (!objectp(actor) || !objectp(room))
    return;

  if (!stringp(spoken_text))
    return;

  spoken_text = trim(spoken_text);

  if (spoken_text == "")
    return;

  actor_name = actor_name_for_event(actor);
  line = actor_name + " says, '" + spoken_text + "'\n";
  ambient_light = room_light_level(room);

  event = ([
    "kind" : "speech.say",
    "source" : "command.say",
    "actor" : actor,
    "origin" : room,
    "destination" : 0,
    "facets" : ({
      ([
        "modality" : "audio",
        "source" : "speech",
        "text" : line,
        "min_sense" : 1
      ]),
      ([
        "modality" : "vision",
        "source" : "speech",
        "text" : actor_name + " speaks.\n",
        "min_sense" : 1,
        "min_light" : 1,
        "ambient_light" : ambient_light
      ])
    })
  ]);

  emit_room_event(actor, room, event);

  return;
}

/* Method Summary:
 * Purpose:
 *   Handles emit_environment_ambience for this object.
 * Parameters:
 *   - object actor, object room, string kind, string line, string modality
 * Approach:
 *   Emits a canonical one-facet ambience event for environmental systems.
 * Side effects:
 *   Routes filtered environmental events through observer experience ingress.
 * Returns:
 *   void result from emit_environment_ambience.
 */
void emit_environment_ambience(
  object actor,
  object room,
  string kind,
  string line,
  string modality
) {
  mapping event;
  string normalized_kind;
  string normalized_modality;

  if (!objectp(room))
    return;

  if (!stringp(kind))
    kind = "";

  if (!stringp(line))
    line = "";

  if (!stringp(modality))
    modality = "";

  normalized_kind = lower_case(trim(kind));
  normalized_modality = lower_case(trim(modality));
  line = trim(line);

  if (normalized_kind == "")
    normalized_kind = "environment.ambient";

  if (!modality_is_valid(normalized_modality))
    normalized_modality = "audio";

  if (line == "")
    return;

  if (line[<1] != '\n')
    line += "\n";

  event = ([
    "kind" : normalized_kind,
    "source" : "environment",
    "actor" : actor,
    "origin" : room,
    "destination" : 0,
    "facets" : ({
      ([
        "modality" : normalized_modality,
        "source" : "environment",
        "text" : line,
        "min_sense" : 1
      ])
    })
  ]);

  emit_room_event(actor, room, event);

  return;
}

/* Method Summary:
 * Purpose:
 *   Handles emit_avatar_presence_departure for this object.
 * Parameters:
 *   - object actor, object room
 * Approach:
 *   Emits room-local avatar departure with visual and auditory facets.
 * Side effects:
 *   Routes filtered presence event text to nearby observers.
 * Returns:
 *   void result from emit_avatar_presence_departure.
 */
void emit_avatar_presence_departure(object actor, object room) {
  mapping event;
  string actor_name;
  int ambient_light;

  if (!objectp(actor) || !objectp(room))
    return;

  actor_name = actor_name_for_event(actor);
  ambient_light = room_light_level(room);

  event = ([
    "kind" : "presence.departure",
    "source" : "presence",
    "actor" : actor,
    "origin" : room,
    "destination" : 0,
    "facets" : ({
      ([
        "modality" : "vision",
        "source" : "presence",
        "text" : "<" + actor_name + " leaves this reality.>\n",
        "min_sense" : 1,
        "min_light" : 1,
        "ambient_light" : ambient_light
      ]),
      ([
        "modality" : "audio",
        "source" : "presence",
        "text" : "A presence thins and fades away.\n",
        "min_sense" : 1
      ])
    })
  ]);

  emit_room_event(actor, room, event);

  return;
}

/* Method Summary:
 * Purpose:
 *   Handles emit_avatar_presence_arrival for this object.
 * Parameters:
 *   - object actor, object room
 * Approach:
 *   Emits room-local avatar arrival with visual and auditory facets.
 * Side effects:
 *   Routes filtered presence event text to nearby observers.
 * Returns:
 *   void result from emit_avatar_presence_arrival.
 */
void emit_avatar_presence_arrival(object actor, object room) {
  mapping event;
  string actor_name;
  int ambient_light;

  if (!objectp(actor) || !objectp(room))
    return;

  actor_name = actor_name_for_event(actor);
  ambient_light = room_light_level(room);

  event = ([
    "kind" : "presence.arrival",
    "source" : "presence",
    "actor" : actor,
    "origin" : room,
    "destination" : 0,
    "facets" : ({
      ([
        "modality" : "vision",
        "source" : "presence",
        "text" : "<" + actor_name + " leaves reality and falls into Moral "
          + "Despair.>\n",
        "min_sense" : 1,
        "min_light" : 1,
        "ambient_light" : ambient_light
      ]),
      ([
        "modality" : "audio",
        "source" : "presence",
        "text" : "A presence tears through the quiet.\n",
        "min_sense" : 1
      ])
    })
  ]);

  emit_room_event(actor, room, event);

  return;
}

/* Method Summary:
 * Purpose:
 *   Handles emit_combat_impact for this object.
 * Parameters:
 *   - object actor, object target, object room, string attack_label, int amount
 * Approach:
 *   Emits canonical combat-impact perception facets for ongoing systems.
 * Side effects:
 *   Routes combat event observations through room sensory filtering.
 * Returns:
 *   void result from emit_combat_impact.
 */
void emit_combat_impact(
  object actor,
  object target,
  object room,
  string attack_label,
  int amount
) {
  mapping event;
  string actor_name;
  string target_name;
  string attack_name;
  int ambient_light;

  if (!objectp(room))
    return;

  actor_name = actor_name_for_event(actor);
  target_name = actor_name_for_event(target);
  if (!stringp(attack_label))
    attack_label = "";

  attack_name = trim(attack_label);

  if (attack_name == "")
    attack_name = "strikes";

  if (!intp(amount))
    amount = 0;

  if (amount < 0)
    amount = 0;

  ambient_light = room_light_level(room);

  event = ([
    "kind" : "combat.impact",
    "source" : "combat",
    "actor" : actor,
    "origin" : room,
    "destination" : target,
    "facets" : ({
      ([
        "modality" : "audio",
        "source" : "combat",
        "text" : "A heavy impact breaks the quiet.\n",
        "min_sense" : 1
      ]),
      ([
        "modality" : "vision",
        "source" : "combat",
        "text" : actor_name + " " + attack_name + " " + target_name + ".\n",
        "min_sense" : 1,
        "min_light" : 1,
        "ambient_light" : ambient_light
      ]),
      ([
        "modality" : "touch",
        "source" : "combat",
        "text" : "Force ripples through the space.\n",
        "min_sense" : 1
      ])
    }),
    "amount" : amount
  ]);

  emit_room_event(actor, room, event);

  return;
}

/* Method Summary:
 * Purpose:
 *   Handles emit_link_action_feedback for this object.
 * Parameters:
 *   - object actor, object room, string feedback_text, string verb
 * Approach:
 *   Emits actor-facing link/gate feedback as a canonical sensory event.
 * Side effects:
 *   Routes perceived feedback through actor experience ingress.
 * Returns:
 *   void result from emit_link_action_feedback.
 */
void emit_link_action_feedback(
  object actor,
  object room,
  string feedback_text,
  string verb
) {
  mapping event;
  string normalized_verb;
  int ambient_light;

  if (!objectp(actor))
    return;

  if (!stringp(feedback_text))
    feedback_text = "";

  feedback_text = trim(feedback_text);

  if (feedback_text == "")
    return;

  if (feedback_text[<1] != '\n')
    feedback_text += "\n";

  if (!stringp(verb))
    verb = "";

  normalized_verb = lower_case(trim(verb));

  if (normalized_verb == "")
    normalized_verb = "interact";

  ambient_light = room_light_level(room);

  event = ([
    "kind" : "link.action_feedback",
    "source" : "link",
    "actor" : actor,
    "origin" : room,
    "destination" : 0,
    "verb" : normalized_verb,
    "facets" : ({
      ([
        "modality" : "audio",
        "source" : "link",
        "text" : feedback_text,
        "min_sense" : 1
      ]),
      ([
        "modality" : "vision",
        "source" : "link",
        "text" : "The way answers.\n",
        "min_sense" : 1,
        "min_light" : 1,
        "ambient_light" : ambient_light
      ])
    })
  ]);

  route_event_to_observer(actor, event);

  return;
}

/* Method Summary:
 * Purpose:
 *   Handles format_arrival_direction for this object.
 * Parameters:
 *   - string direction
 * Approach:
 *   Provides localized movement phrasing for arrival messages.
 * Side effects:
 *   None.
 * Returns:
 *   string result from format_arrival_direction.
 */
string format_arrival_direction(string direction) {
  string normalized;

  if (!stringp(direction) || direction == "")
    return "";

  normalized = lower_case(trim(direction));

  if (member_array(normalized, ({
    "n",
    "s",
    "e",
    "w",
    "ne",
    "nw",
    "se",
    "sw",
    "north",
    "south",
    "east",
    "west",
    "northeast",
    "northwest",
    "southeast",
    "southwest"
  })) != -1)
    return "the " + normalized;

  return normalized;
}

/* Method Summary:
 * Purpose:
 *   Handles ensure_line_break for this object.
 * Parameters:
 *   - string line
 * Approach:
 *   Normalizes event line text to terminate with a newline.
 * Side effects:
 *   None.
 * Returns:
 *   string result from ensure_line_break.
 */
string ensure_line_break(string line) {
  if (!stringp(line))
    return "";

  if (line == "")
    return "";

  if (line[<1] != '\n')
    line += "\n";

  return line;
}

/* Method Summary:
 * Purpose:
 *   Handles movement_event_payload for this object.
 * Parameters:
 *   - object actor, string phase, object room, string direction
 * Approach:
 *   Builds movement facets and synthesis with optional actor overrides.
 * Side effects:
 *   None.
 * Returns:
 *   mapping result from movement_event_payload.
 */
mapping movement_event_payload(
  object actor,
  string phase,
  object room,
  string direction
) {
  mapping payload;
  mapping actor_payload;
  string actor_name;
  string anonymous_name;
  string movement_phrase;
  string visible_line;
  string audible_line;
  string both_line;
  string audio_cue;
  int ambient_light;

  actor_name = actor_name_for_event(actor);
  anonymous_name = "Something";
  movement_phrase = "";
  audio_cue = "with the sound of footsteps.";
  ambient_light = room_light_level(room);

  if (!stringp(phase))
    phase = "departure";

  phase = lower_case(trim(phase));

  if (phase == "arrival")
    movement_phrase = "arrives from " + direction;
  else
    movement_phrase = "leaves " + direction;

  visible_line = actor_name + " " + movement_phrase + ".";
  audible_line = "Footsteps " + (phase == "arrival" ? "approach from " : "fade ")
    + direction + ".";
  both_line = actor_name + " " + movement_phrase + " " + audio_cue;

  if (function_exists("movement_event_payload", actor))
    actor_payload = actor->movement_event_payload(phase, direction, actor_name, room);

  if (mapp(actor_payload)) {
    if (stringp(actor_payload["anonymous_name"]) && actor_payload["anonymous_name"] != "")
      anonymous_name = actor_payload["anonymous_name"];

    if (stringp(actor_payload["audio_cue"]) && actor_payload["audio_cue"] != "")
      audio_cue = actor_payload["audio_cue"];

    if (stringp(actor_payload["visible_line"]) && actor_payload["visible_line"] != "")
      visible_line = actor_payload["visible_line"];

    if (stringp(actor_payload["audible_line"]) && actor_payload["audible_line"] != "")
      audible_line = actor_payload["audible_line"];

    if (stringp(actor_payload["both_line"]) && actor_payload["both_line"] != "")
      both_line = actor_payload["both_line"];
  }

  payload = ([
    "facets" : ({
      ([
        "modality" : "vision",
        "source" : "movement",
        "text" : ensure_line_break(visible_line),
        "min_sense" : 1,
        "min_light" : 1,
        "ambient_light" : ambient_light
      ]),
      ([
        "modality" : "audio",
        "source" : "movement",
        "text" : ensure_line_break(audible_line),
        "min_sense" : 1
      ])
    }),
    "synthesis" : ([
      "vision+audio" : ensure_line_break(both_line),
      "vision" : ensure_line_break(visible_line),
      "audio" : ensure_line_break(anonymous_name + " " + movement_phrase + " "
        + audio_cue),
      "default" : ensure_line_break(visible_line)
    ])
  ]);

  if (mapp(actor_payload) && mapp(actor_payload["synthesis"]))
    payload["synthesis"] = copy(actor_payload["synthesis"]);

  if (mapp(actor_payload) && pointerp(actor_payload["facets"]))
    payload["facets"] = copy(actor_payload["facets"]);

  return payload;
}

/* Method Summary:
 * Purpose:
 *   Handles emit_movement_departure for this object.
 * Parameters:
 *   - object actor, object origin, string direction
 * Approach:
 *   Emits a movement departure event with vision and audio facets.
 * Side effects:
 *   Routes movement observation to nearby observers in the origin room.
 * Returns:
 *   void result from emit_movement_departure.
 */
void emit_movement_departure(object actor, object origin, string direction) {
  mapping event;
  mapping payload;
  string normalized_direction;

  if (!objectp(actor) || !objectp(origin))
    return;

  normalized_direction = trim(lower_case(direction));

  if (!stringp(normalized_direction) || normalized_direction == "")
    normalized_direction = "away";
  payload = movement_event_payload(actor, "departure", origin, normalized_direction);

  event = ([
    "kind" : "movement.departure",
    "source" : "move_d",
    "actor" : actor,
    "origin" : origin,
    "destination" : 0,
    "facets" : payload["facets"],
    "synthesis" : payload["synthesis"]
  ]);

  emit_room_event(actor, origin, event);

  return;
}

/* Method Summary:
 * Purpose:
 *   Handles emit_movement_arrival for this object.
 * Parameters:
 *   - object actor, object destination, string direction
 * Approach:
 *   Emits a movement arrival event with vision and audio facets.
 * Side effects:
 *   Routes movement observation to nearby observers in the destination room.
 * Returns:
 *   void result from emit_movement_arrival.
 */
void emit_movement_arrival(object actor, object destination, string direction) {
  mapping event;
  mapping payload;
  string formatted_direction;

  if (!objectp(actor) || !objectp(destination))
    return;

  formatted_direction = format_arrival_direction(direction);

  if (!stringp(formatted_direction) || formatted_direction == "")
    formatted_direction = "nearby";
  payload = movement_event_payload(actor, "arrival", destination, formatted_direction);

  event = ([
    "kind" : "movement.arrival",
    "source" : "move_d",
    "actor" : actor,
    "origin" : 0,
    "destination" : destination,
    "facets" : payload["facets"],
    "synthesis" : payload["synthesis"]
  ]);

  emit_room_event(actor, destination, event);

  return;
}
