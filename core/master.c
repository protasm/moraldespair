#include <globals.h>

#include "/inherit/master/valid.c"

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

object compile_object(string file) {
write("/core/master:compile_object " + file + "\n");
  string room_id;
  object room;

  if (!stringp(file))
    return 0;

  if (sscanf(file, "/chapter/prologue/std/wilderness_room#%s", room_id) != 1)
    return 0;

  room = "/chapter/prologue/std/vmaster"->compile_object(
    "wilderness_room#" + room_id
  );

  return room;
}

object connect() {
  return new(LOGIN_OB);
}
