int load_json(string file);
string *endpoints_from_key(string key);
string normalize_endpoint(string value);

/* Alphabetized forward declarations for core/daemon/link_d.c */

/* Alphabetized forward declarations (ctags) for core/daemon/link_d.c */
string _definition_source(mapping definition);
string _format_definition_ref(string key, mapping definition);
object _instantiate_link(string a, string b, mapping def);
string _opposite_direction(string dir);
string _trim(string s);
string *collect_area_link_files(string area_dir, mapping visited_dirs);
void create();
int define_link(string env_a, string env_b, mapping definition);
string *defined_link_pairs();
string *defined_pairs_for_room(string room);
mapping definition(string env_a, string env_b);
string *endpoints_from_key(string key);
object get_link(string env_a, string env_b);
int has_definition(string env_a, string env_b);
void index_pair_for_room(string room, string key);
string *instantiated_link_pairs();
string join_path(string base, string entry);
object link(string env_a, string env_b);
mapping links_by_direction_for_room(string room);
object *links_for_room(string room);
int load_json(string file);
string normalize_endpoint(string value);
string normalize_prefix(string prefix);
string pair_key(string a, string b);
mixed parse_json(string raw);
string read_json_file(string file);
string resolve_endpoint(string endpoint_ref, string prefix);
string *sub_area_dirs_from_json(string area_dir);
