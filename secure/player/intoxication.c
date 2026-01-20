/* ------------------------------------------------------------------------- */
/* Intoxication, fullness, and thirst. */

static string intoxication_status_message() {
  string tmp;

  if (!intoxicated && !stuffed && !soaked)
    return 0;

  tmp = "You are ";

  if (intoxicated) {
    tmp += "intoxicated";
    if (stuffed && soaked)
      tmp += ", ";
    else {
      if (stuffed || soaked)
        tmp += " and ";
      else
        tmp += ".\n";
    }
  }

  if (stuffed) {
    tmp += "satiated";

    if (soaked)
      tmp += " and ";
    else
      tmp += ".\n";
  }

  if (soaked)
    tmp += "not thirsty.\n";

  return tmp;
}

static void handle_intoxication_emotes() {
  int roll;

  if (!intoxicated || random(40) != 0)
    return;

  roll = random(7);
  if (roll == 0) {
    say(cap_name + " hiccups.\n");
    write("You hiccup.\n");
  }
  if (roll == 1) {
    say(cap_name + " seems to fall, but takes a step and recovers.\n");
    write("You stumble.\n");
  }
  if (roll == 3) {
    write("You feel drunk.\n");
    say(cap_name + " looks drunk.\n");
  }
  if (roll == 5) {
    say(cap_name + " burps.\n");
    write("You burp.\n");
  }
}

static void handle_headache_recovery() {
  if (!headache)
    return;

  headache -= 1;
  if (headache == 0)
    tell_object(player_self, "You no longer have a headache.\n");
}

static void handle_intoxication_recovery() {
  if (!intoxicated)
    return;

  intoxicated -= 1;
  if (intoxicated == 0) {
    headache = max_headache;
    max_headache = 0;
    tell_object(player_self,
                "You suddenly without reason get a bad headache.\n");
    hit_point -= 3;
    if (hit_point < 0)
      hit_point = 0;
  }
}

static void decay_food_and_drink() {
  if (stuffed)
    stuffed--;

  if (soaked)
    soaked--;
}

/* Adjusts intoxication. */
void add_intoxination(int i) {
  if (i < 0) {
    if (-i > intoxicated / 10)
      i = -intoxicated / 10;
  }
  intoxicated += i;
  if (intoxicated < 0)
    intoxicated = 0;
}

/* Adjusts fullness. */
void add_stuffed(int i) {
  if (i < 0) {
    if (-i > stuffed / 10)
      i = -stuffed / 10;
  }
  stuffed += i;
  if (stuffed < 0)
    stuffed = 0;
}

/* Adjusts thirst. */
void add_soaked(int i) {
  if (i < 0) {
    if (-i > soaked / 10)
      i = -soaked / 10;
  }
  soaked += i;
  if (soaked < 0)
    soaked = 0;
}

/* Returns intoxication level. */
int query_intoxination() {
  return intoxicated;
}

/* Returns stuffed level. */
int query_stuffed() {
  return stuffed;
}

/* Returns soaked level. */
int query_soaked() {
  return soaked;
}

/* Handles drinking alcohol with full strength. */
int drink_alcohol(int strength) {
  if (intoxicated > level + 3) {
    write("You fail to reach the drink with your mouth.\n");
    return 0;
  }
  intoxicated += strength;
  if (intoxicated < 0)
    intoxicated = 0;
  if (intoxicated == 0)
    write("You are completely sober.\n");
  if (intoxicated > 0 && headache) {
    headache = 0;
    tell_object(player_self, "Your headache disappears.\n");
  }
  if (intoxicated > max_headache)
    max_headache = intoxicated;
  if (max_headache > 8)
    max_headache = 8;
  return 1;
}

/* Handles drinking alcohol with reduced strength. */
int drink_alco(int strength) {
  if (intoxicated + strength > level * 3) {
    write("You fail to reach the drink with your mouth.\n");
    return 0;
  }

  intoxicated += strength / 2;

  if (intoxicated < 0)
    intoxicated = 0;

  if (intoxicated == 0)
    write("You are completely sober.\n");

  if (intoxicated > 0 && headache) {
    headache = 0;
    tell_object(player_self, "Your headache disappears.\n");
  }

  if (intoxicated > max_headache)
    max_headache = intoxicated;

  if (max_headache > 8)
    max_headache = 8;

  return 1;
}

/* Handles drinking non-alcoholic drinks. */
int drink_soft(int strength) {
  if (soaked + strength > level * 8) {
    write("You can't possibly drink that much right now!\n" +
          "You feel crosslegged enough as it is.\n");
    return 0;
  }

  soaked += strength * 2;

  if (soaked < 0)
    soaked = 0;

  if (soaked == 0)
    write("You feel a bit dry in the mouth.\n");

  return 1;
}

/* Handles eating food. */
int eat_food(int strength) {
  if (stuffed + strength > level * 8) {
    write("This is much too rich for you right now! Perhaps something "
          "lighter?\n");
    return 0;
  }

  stuffed += strength * 2;

  if (stuffed < 0)
    stuffed = 0;

  if (stuffed == 0)
    write("Your stomach makes a rumbling sound.\n");

  return 1;
}
