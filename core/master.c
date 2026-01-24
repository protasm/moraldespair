string get_root_uid() {
  return "Root";
}

string get_bb_uid() {
  return "Backbone";
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
