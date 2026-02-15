/* Forward declarations for core/daemon/room_data_d.c */

/* Alphabetized forward declarations (ctags) for core/daemon/room_data_d.c */
string area_dir_from_json_file(string json_file);
string chapter_dir_from_area_dir(string area_dir);
string *collect_area_room_json_files(string area_dir, mapping visited_dirs);
void create();
mapping debug_status();
void index_room_entry(string json_file, mapping json_root, mapping room_entry);
string join_path(string base, string entry);
string *legacy_room_json_files(string area_dir);
void load_room_data();
void load_room_json(string json_file);
string normalize_path(string path);
mixed parse_json(string raw);
string read_json_file(string file);
void reload_room_data();
mapping resolve_room_request(string requested_path);
mapping room_data(string room_path);
int room_exists(string room_path);
string *sub_area_dirs_from_json(string area_dir);
mapping terrain_catalog_for_area_dir(string area_dir);
mapping virtual_spec(string room_path);
