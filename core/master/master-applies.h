/* Companion header file. */

/* Alphabetized forward declarations for core/master/master-applies.c */
varargs string parser_error_message(int error_type, object ob, mixed args...);

/* Alphabetized forward declarations (ctags) for core/master/master-applies.c */
string author_file(string file);
object compile_object(string pathname);
object connect(int port);
void crash(string crash_message, object command_giver, object current_object);
string creator_file(string filename);
string domain_file(string file);
string *epilog(int load_empty);
void error_handler(mapping error, int caught);
void flag(string flag_name);
string get_bb_uid();
mixed get_include_path(string object_path);
mapping get_mud_stats();
string get_root_uid();
string get_save_file_name(string original_file_name, object who);
void log_error(string file, string message);
string make_path_absolute(string rel_path);
string normalize_path(string path);
string object_name(object ob);
varargs string parser_error_message(int error_type, object ob, mixed args...);
void preload(string filename);
string privs_file(string filename);
int retrieve_ed_setup(object user);
int save_ed_setup(object user, int config);
void wizard_virtual_debug(string message);
