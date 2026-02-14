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
  return ({
    "/daemon/link_d",
    "/daemon/wilderness_d",
    "/daemon/room_data_d"
  });
}

void preload(string filename) {
  mixed load_error;

  if (!stringp(filename) || filename == "")
    return;

  load_error = catch(load_object(filename));

  if (load_error)
    write_file("/log/compile", filename + ": preload failed: " + load_error);

  return;
}

void log_error(string file, string message) {
  write_file("/log/compile", file + ": " + message);

  return;
}

string normalize_path(string path) {
  if (!stringp(path) || path == "")
    return "";

  if (path[0] != '/')
    path = "/" + path;

  if (sizeof(path) > 2 && path[<2..<1] == ".c")
    path = path[0..<3];

  while (strsrch(path, "//") != -1)
    path = replace_string(path, "//", "/");

  return path;
}

object compile_object(string pathname) {
  object room;
  object room_data_daemon;
  mapping resolved_spec;
  string normalized_path;
  string custom_path;
  string virtual_path;
  string template;
  string room_id;

  if (!stringp(pathname))
    return 0;

  normalized_path = normalize_path(pathname);

  if (normalized_path == "")
    return 0;

  room_id = "";

  if (sscanf(normalized_path, "/chapter/prologue/std/wilderness_room#%s", room_id) == 1) {
    room = "/chapter/prologue/std/vmaster"->compile_object(
      "wilderness_room#" + room_id
    );

    return room;
  }

  if (file_size(normalized_path + ".c") > 0) {
    room = load_object(normalized_path);

    return room;
  }

  room_data_daemon = find_object("/daemon/room_data_d");

  if (!objectp(room_data_daemon))
    room_data_daemon = load_object("/daemon/room_data_d");

  if (!objectp(room_data_daemon))
    return 0;

  resolved_spec = room_data_daemon->resolve_room_request(normalized_path);

  if (!mapp(resolved_spec))
    return 0;

  custom_path = resolved_spec["custom_path"];

  if (stringp(custom_path) && custom_path != "" &&
      file_size(custom_path + ".c") > 0) {
    room = load_object(custom_path);

    return room;
  }

  virtual_path = resolved_spec["path"];
  template = resolved_spec["template"];
  room_id = resolved_spec["id"];

  if (!stringp(virtual_path) || virtual_path == "")
    return 0;

  if (stringp(template) && template == "wilderness_room" && stringp(room_id)) {
    room = "/chapter/prologue/std/vmaster"->compile_object(
      "wilderness_room#" + room_id
    );

    return room;
  }

  room = "/chapter/prologue/std/vmaster"->compile_object(
    "data_room#" + virtual_path
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
#if ENABLE_RUNTIME_ERROR_LOG
  string line;

  line = ctime(time()) + " caught=" + caught + " " + save_variable(error) + "\n";
  write_file("/log/runtime", line);
#endif

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
