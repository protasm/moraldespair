#include <globals.h>

#include "valid.c"

string get_root_uid() {
  return ROOT_UID;
}

string get_bb_uid() {
  return BACKBONE_UID;
}

string creator_file(string filename) {
  return get_root_uid();
}

string domain_file(string file) {
  return get_bb_uid();
}

string author_file(string file) {
  return get_root_uid();
}

string *epilog(int load_empty) {
  return ({});
}

void preload(string filename) {
  return;
}

void log_error(string file, string message) {
  write_file("/log/compile", file + ": " + message);

  return;
}

object compile_object(string pathname) {
  string room_id;
  object room;

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
  return new(LOGIN_OB);
}

void crash(string crash_message, object command_giver, object current_object) {
  return;
}

void error_handler(mapping error, int caught) {
  return;
}

void flag(string flag_name) {
  return;
}

mixed get_include_path(string object_path) {
  return ({ "/include" });
}

mapping get_mud_stats() {
  return ([]);
}

string get_save_file_name(string original_file_name, object who) {
  return original_file_name;
}

string make_path_absolute(string rel_path) {
  return rel_path;
}

string object_name(object ob) {
  if (!objectp(ob))
    return 0;

  return file_name(ob);
}

varargs string parser_error_message(int error_type, object ob, mixed args...) {
  return 0;
}

string privs_file(string filename) {
  return get_root_uid();
}

int retrieve_ed_setup(object user) {
  return 0;
}

int save_ed_setup(object user, int config) {
  return 0;
}
