#include <globals.h>

string get_root_uid() {
  return ROOT_UID;
}

string get_bb_uid() {
  return BACKBONE_UID;
}

string creator_file(string file) {
  return get_root_uid();
}

string domain_file(string file) {
  return get_bb_uid();
}

string author_file(string file) {
  return get_root_uid();
}

string get_simul_efun() {
  return MFUN_OB;
}

string *epilog(int) {
  return ({});
}

void preload(string) {
  return;
}

void log_error(string file, string message) {
  write_file("/log/compile", file + ": " + message);
}

object connect() {
  return new(LOGIN_OB);
}
