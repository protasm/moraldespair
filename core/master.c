string get_root_uid() {
  return "Root";
}

string get_bb_uid() {
  return "Backbone";
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
  return "/core/simul_efun";
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
  object login_ob;

  login_ob = new("/core/login");

  return login_ob;
}
