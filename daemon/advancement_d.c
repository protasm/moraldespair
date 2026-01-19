#include "tune.h"

static int next_level;
static int next_exp;
static int level;
static int exp;
static string title;
static object player_ob;

static string *male_title_str;
static string *fem_title_str;
static string *neut_title_str;
static int *exp_str;

static void get_level(int current_level);
static string get_new_title(int current_level);
static int get_next_exp(int current_level);
static int raise_cost(int base, int action);
static void raise_con();
static void raise_dex();
static void raise_int();
static void raise_str();
static int too_high_average();
static void alas(string description);
static string gnd_prn();

static void get_level(int current_level) {
  level = current_level;
  next_exp = get_next_exp(level);
  next_level = level + 1;
  title = get_new_title(level);
}

static string get_new_title(int current_level) {
  if (!male_title_str) {
    male_title_str = allocate(20);
    male_title_str[19] = "the apprentice Wizard";
    male_title_str[18] = "the grand master sorcerer";
    male_title_str[17] = "the master sorcerer";
    male_title_str[16] = "the apprentice sorcerer";
    male_title_str[15] = "the warlock";
    male_title_str[14] = "the enchanter";
    male_title_str[13] = "the magician";
    male_title_str[12] = "the apprentice magician";
    male_title_str[11] = "the conjurer";
    male_title_str[10] = "the champion";
    male_title_str[9] = "the warrior";
    male_title_str[8] = "the great adventurer";
    male_title_str[7] = "the experienced adventurer";
    male_title_str[6] = "the small adventurer";
    male_title_str[5] = "the experienced fighter";
    male_title_str[4] = "the small fighter";
    male_title_str[3] = "the master ranger";
    male_title_str[2] = "the lowrank ranger";
    male_title_str[1] = "the simple wanderer";
    male_title_str[0] = "the utter novice";

    fem_title_str = allocate(20);
    fem_title_str[19] = "the apprentice Wizard";
    fem_title_str[18] = "the grand master sorceress";
    fem_title_str[17] = "the master sorceress";
    fem_title_str[16] = "the apprentice sorceress";
    fem_title_str[15] = "the witch";
    fem_title_str[14] = "the enchantress";
    fem_title_str[13] = "the magicienne";
    fem_title_str[12] = "the apprentice magicienne";
    fem_title_str[11] = "the conjuress";
    fem_title_str[10] = "the deadly amazon";
    fem_title_str[9] = "the amazon";
    fem_title_str[8] = "the great adventuress";
    fem_title_str[7] = "the experienced adventuress";
    fem_title_str[6] = "the small adventuress";
    fem_title_str[5] = "the charming siren";
    fem_title_str[4] = "the siren";
    fem_title_str[3] = "the master ranger";
    fem_title_str[2] = "the lowrank ranger";
    fem_title_str[1] = "the simple wanderer";
    fem_title_str[0] = "the utter novice";

    neut_title_str = allocate(20);
    neut_title_str[19] = "the apprentice Wizard";
    neut_title_str[18] = "the ferocious tyrannosaur";
    neut_title_str[17] = "the small tyrannosaur";
    neut_title_str[16] = "the vicious dragon";
    neut_title_str[15] = "the devious dragon";
    neut_title_str[14] = "the small dragon";
    neut_title_str[13] = "the powerful demon";
    neut_title_str[12] = "the small demon";
    neut_title_str[11] = "the beholder";
    neut_title_str[10] = "the great monster";
    neut_title_str[9] = "the experienced monster";
    neut_title_str[8] = "the medium monster";
    neut_title_str[7] = "the small monster";
    neut_title_str[6] = "the threatening shadow";
    neut_title_str[5] = "the shadow";
    neut_title_str[4] = "the wraith";
    neut_title_str[3] = "the bugbear";
    neut_title_str[2] = "the furry creature";
    neut_title_str[1] = "the simple creature";
    neut_title_str[0] = "the utter creature";
  }

  if (!player_ob || !player_ob->query_gender())
    return neut_title_str[current_level];
  else if (player_ob->query_gender() == 1)
    return male_title_str[current_level];
  else
    return fem_title_str[current_level];
}

static int get_next_exp(int current_level) {
  if (!exp_str) {
    exp_str = allocate(20);
    exp_str[19] = 1000000;
    exp_str[18] = 666666;
    exp_str[17] = 444444;
    exp_str[16] = 296296;
    exp_str[15] = 197530;
    exp_str[14] = 131687;
    exp_str[13] = 97791;
    exp_str[12] = 77791;
    exp_str[11] = 58527;
    exp_str[10] = 39018;
    exp_str[9] = 26012;
    exp_str[8] = 17341;
    exp_str[7] = 11561;
    exp_str[6] = 7707;
    exp_str[5] = 5138;
    exp_str[4] = 3425;
    exp_str[3] = 2283;
    exp_str[2] = 1522;
    exp_str[1] = 1014;
    exp_str[0] = 676;
  }

  if (current_level < 0)
    return 0;

  if (current_level >= sizeof(exp_str))
    return exp_str[sizeof(exp_str) - 1];

  return exp_str[current_level];
}

int query_cost(int current_level) {
  player_ob = this_player();
  level = current_level;

  if (level >= 20)
    return 1000000;

  get_level(level);

  return next_exp;
}

int query_cost_for_level(int current_level, int current_exp) {
  level = current_level;
  exp = current_exp;
  get_level(0);

  if (next_exp <= exp)
    return 0;

  return (next_exp - exp) * 1000 / EXP_COST;
}

int advance(string arg) {
  string name_of_player;
  int cost;

  if (arg == "con") {
    raise_con();
    return 1;
  }

  if (arg == "dex") {
    raise_dex();
    return 1;
  }

  if (arg == "int") {
    raise_int();
    return 1;
  }

  if (arg == "str") {
    raise_str();
    return 1;
  }

  if (arg && arg != "level")
    return 0;

  player_ob = this_player();
  if (!player_ob)
    return 0;

  name_of_player = player_ob->query_name();
  level = player_ob->query_level();

  if (level == -1)
    level = 0;

  exp = player_ob->query_exp();
  title = player_ob->query_title();

  if (level >= 20) {
    write("You are still ");
    write(title);
    write("\n");
    return 1;
  }

  get_level(level);

  if (level == 0)
    next_exp = exp;

  cost = (next_exp - exp) * 1000 / EXP_COST;

  if (next_exp > exp) {
    if (player_ob->query_money() < cost) {
      write("You don't have enough gold coins.\n");
      return 1;
    }
    player_ob->add_money(-cost);
  }

  say(player_ob->query_name() + " is now level " + next_level + ".\n");
  player_ob->set_level(next_level);
  player_ob->set_title(title);

  if (exp < next_exp)
    player_ob->add_exp(next_exp - exp);

  if (next_level < 7) {
    write("You are now " + name_of_player + " " + title +
          " (level " + next_level + ").\n");
    return 1;
  }

  if (next_level < 14) {
    write("Well done, " + name_of_player + " " + title +
          " (level " + next_level + ").\n");
    return 1;
  }

  if (next_level < 20) {
    write("Welcome to your new class, mighty one.\n" +
          "You are now " + title + " (level " + next_level + ").\n");
  }

  if (next_level == 20) {
    write("A new Wizard has been born.\n");
    shout("A new Wizard has been born.\n");
    return 1;
  }

  return 1;
}

static void raise_con() {
  int lvl;

  if (too_high_average())
    return;

  lvl = this_player()->query_con();

  if (lvl >= 20) {
    alas("tough and endurable");
    return;
  }

  if (raise_cost(lvl, 1)) {
    this_player()->set_con(lvl + 1);
    write("Ok.\n");
  } else
    write("You don't have enough experience.\n");
}

static void raise_dex() {
  int lvl;

  if (too_high_average())
    return;

  lvl = this_player()->query_dex();

  if (lvl >= 20) {
    alas("skilled and vigorous");
    return;
  }

  if (raise_cost(lvl, 1)) {
    this_player()->set_dex(lvl + 1);
    write("Ok.\n");
  } else
    write("You don't have enough experience.\n");
}

static void raise_int() {
  int lvl;

  if (too_high_average())
    return;

  lvl = this_player()->query_int();

  if (lvl >= 20) {
    alas("knowledgeable and wise");
    return;
  }

  if (raise_cost(lvl, 1)) {
    this_player()->set_int(lvl + 1);
    write("Ok.\n");
  } else
    write("You don't have enough experience.\n");
}

static void raise_str() {
  int lvl;

  if (too_high_average())
    return;

  lvl = this_player()->query_str();

  if (lvl >= 20) {
    alas("strong and powerful");
    return;
  }

  if (raise_cost(lvl, 1)) {
    this_player()->set_str(lvl + 1);
    write("Ok.\n");
  } else
    write("You don't have enough experience.\n");
}

static int raise_cost(int base, int action) {
  int cost;
  int saldo;
  int level_index;

  if (base >= 20)
    return 0;

  cost = (get_next_exp(base) - get_next_exp(base - 1)) / STAT_COST;
  level_index = this_player()->query_level() - 1;

  if (level_index < 0)
    level_index = 0;

  saldo = this_player()->query_exp() - get_next_exp(level_index);

  if (action == 0)
    return cost;

  if (saldo < cost)
    return 0;

  this_player()->add_exp(-cost);

  return cost;
}

static void alas(string description) {
  write("Sorry " + gnd_prn() + ", but you are already as " + description +
        "\nas any");

  if (this_player()->query_gender() == 0)
    write("thing could possibly hope to get.\n");
  else
    write("one could possibly hope to get.\n");
}

static int too_high_average() {
  if ((this_player()->query_con() + this_player()->query_str() +
       this_player()->query_int() + this_player()->query_dex()) / 4 >=
      this_player()->query_level() + 3) {
    write("Sorry " + gnd_prn() +
          ", but you are not of high enough level.\n");
    return 1;
  }

  return 0;
}

static string gnd_prn() {
  int gnd;

  gnd = this_player()->query_gender();

  if (gnd == 1)
    return "sir";
  else if (gnd == 2)
    return "madam";
  else
    return "best creature";
}
