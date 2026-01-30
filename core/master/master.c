#include <globals.h>

#include "valid.c"

string get_root_uid() {
  write("master:get_root_uid()\n");
  write("-- <no args>\n");

  return ROOT_UID;
}

string get_bb_uid() {
  write("master:get_bb_uid()\n");
  write("-- <no args>\n");

  return BACKBONE_UID;
}

string creator_file(string filename) {
  write("master:creator_file()\n");
  write("-- filename: " + filename + "\n");

  return get_root_uid();
}

string domain_file(string file) {
  write("master:domain_file()\n");
  write("-- file: " + file + "\n");

  return get_bb_uid();
}

string author_file(string file) {
  write("master:author_file()\n");
  write("-- file: " + file + "\n");

  return get_root_uid();
}

string *epilog(int load_empty) {
  write("master:epilog()\n");
  write("-- load_empty: " + load_empty + "\n");

  return ({});
}

void preload(string filename) {
  write("master:preload()\n");
  write("-- filename: " + filename + "\n");

  return;
}

void log_error(string file, string message) {
  write("master:log_error():\n");
  write("-- file: " + file + "\n");
  write("-- message: " + message + "\n");

  write_file("/log/compile", file + ": " + message);

  return;
}

object compile_object(string pathname) {
  string room_id;
  object room;

  write("master:compile_object()\n");
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
  write("master:connect()\n");
  write("-- port: " + port + "\n");

  return new(LOGIN_OB);
}

void crash(string crash_message, object command_giver, object current_object) {
  write("master:crash()\n");
  write("-- <numerous args>\n");

  return;
}

void error_handler(mapping error, int caught) {
  write("master:error_handler()\n");
  write("-- <numerous args>\n");

  return;
}

void flag(string flag_name) {
  write("master:flag()\n");
  write("-- flag_name: " + flag_name + "\n");

  return;
}

mixed get_include_path(string object_path) {
  write("master:get_include_path()\n");
  write("-- object_path: " + object_path + "\n");

  return ({ "/include" });
}

mapping get_mud_stats() {
  write("master:get_mud_stats()\n");

  return ([]);
}

string get_save_file_name(string original_file_name, object who) {
  write("master:get_save_file_name()\n");
  write("-- <numerous args>\n");

  return original_file_name;
}

string make_path_absolute(string rel_path) {
  write("master:make_path_absolute()\n");
  write("-- rel_path: " + rel_path + "\n");

  return rel_path;
}

string object_name(object ob) {
  write("master:object_name()\n");
  write("-- ob: " + ob + "\n");

  if (!objectp(ob))
    return 0;

  return file_name(ob);
}

varargs string parser_error_message(int error_type, object ob, mixed args...) {
  write("master:parser_error_message()\n");
  write("-- <numerous args>\n");

  return 0;
}

string privs_file(string filename) {
  write("master:privs_file()\n");
  write("-- filename: " + filename + "\n");

  return get_root_uid();
}

int retrieve_ed_setup(object user) {
  write("master:retrieve_ed_setup()\n");

  return 0;
}

int save_ed_setup(object user, int config) {
  write("master:save_ed_setup()\n");

  return 0;
}
