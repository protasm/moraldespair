/*
 * Character stat variables.
 */
int Str, Int, Con, Dex;
int max_hp, max_sp;

string query_stats() {
  return "str:\t" + Str + "\nint:\t" + Int + "\ncon:\t" + Con + "\ndex:\t" +
    Dex + "\n";
}

int query_str() {
  return Str;
}
int query_int() {
  return Int;
}
int query_con() {
  return Con;
}
int query_dex() {
  return Dex;
}

/* Note that previous object is 0 if called from ourselves. */
void set_str(int i) {
  if (i < 1 || i > 20)
    return;

  Str = i;
}

void set_int(int i) {
  if (i < 1 || i > 20)
    return;

  Int = i;
  max_sp = 42 + Int * 8;
}

void set_con(int i) {
  if (i < 1 || i > 20)
    return;

  Con = i;
  max_hp = 42 + Con * 8;
}

void set_dex(int i) {
  if (i < 1 || i > 20)
    return;

  Dex = i;
}
