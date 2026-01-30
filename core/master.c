#include <globals.h>

#include "/inherit/master/valid.c"

string get_root_uid() {
  write("apply get_root_uid called in master\n");
  write("-- <no args>\n");

  return ROOT_UID;
}

string get_bb_uid() {
  write("apply get_bb_uid called in master\n");
  write("-- <no args>\n");

  return BACKBONE_UID;
}

string creator_file(string filename) {
  write("apply creator_file called in master\n");
  write("-- filename: " + filename + "\n");

  return get_root_uid();
}

string domain_file(string file) {
  write("apply domain_file called in master\n");
  write("-- file: " + file + "\n");

  return get_bb_uid();
}

string author_file(string file) {
  write("apply author_file called in master\n");
  write("-- file: " + file + "\n");

  return get_root_uid();
}

string *epilog(int load_empty) {
  write("apply epilog called in master\n");
  write("-- load_empty: " + load_empty + "\n");

  return ({});
}

void preload(string filename) {
  write("apply preload called in master\n");
  write("-- filename: " + filename + "\n");

  return;
}

void log_error(string file, string message) {
  write("apply log_error called in master:\n");
  write("-- file: " + file + "\n");
  write("-- message: " + message + "\n");

  write_file("/log/compile", file + ": " + message);

  return;
}

object compile_object(string pathname) {
  string room_id;
  object room;

  write("apply compile_object called in master\n");
  write("-- pathname: " + pathname + "\n");

  if (!stringp(pathname))
    return 0;

  if (sscanf(pathname, "/chapter/prologue/std/wilderness_room#%s", room_id) != 1)
    return 0;

  room = "/chapter/prologue/std/vmaster"->compile_object(
    "wilderness_room#" + room_id
  );

  return room;
}

object connect(int port) {
  write("apply connect called in master\n");
  write("-- port: " + port + "\n");

  return new(LOGIN_OB);
}

void crash(string crash_message, object command_giver, object current_object) {
  write("apply crash called in master\n");
  write("-- <numerous args>\n");

  return;
}

void error_handler(mapping error, int caught) {
  write("apply error_handler called in master\n");
  write("-- <numerous args>\n");

  return;
}

void flag(string flag_name) {
  write("apply flag called in master\n");
  write("-- flag_name: " + flag_name + "\n");

  return;
}

mixed get_include_path(string object_path) {
  write("apply get_include_path called in master\n");
  write("-- object_path: " + object_path + "\n");

  return ({ "/include" });
}

mapping get_mud_stats() {
  write("apply get_mud_stats called in master\n");

  return ([]);
}

string get_save_file_name(string original_file_name, object who) {
  write("apply get_save_file_name called in master\n");
  write("-- <numerous args>\n");

  return original_file_name;
}

string make_path_absolute(string rel_path) {
  write("apply make_path_absolute called in master\n");
  write("-- rel_path: " + rel_path + "\n");

  return rel_path;
}

string object_name(object ob) {
  write("apply object_name called in master\n");
  write("-- ob: " + ob + "\n");

  if (!objectp(ob))
    return 0;

  return file_name(ob);
}

varargs string parser_error_message(int error_type, object ob, mixed args...) {
  write("apply parser_error_message called in master\n");
  write("-- <numerous args>\n");

  return 0;
}

string privs_file(string filename) {
  write("apply privs_file called in master\n");
  write("-- filename: " + filename + "\n");

  return get_root_uid();
}

int retrieve_ed_setup(object user) {
  write("apply retrieve_ed_setup called in master\n");

  return 0;
}

int save_ed_setup(object user, int config) {
  write("apply save_ed_setup called in master\n");

  return 0;
}

int valid_database(object caller, string func, mixed *info) {
  write("apply valid_database called in master\n");

  return 1;
}

int valid_link(string from, string to) {
  write("apply valid_link called in master\n");

  return 1;
}

int valid_object(object obj) {
  write("apply valid_object called in master\n");
  write("-- obj: " + obj + "\n");

  return 1;
}

int valid_save_binary(string file) {
  write("apply valid_save_binary called in master\n");

  return 1;
}
