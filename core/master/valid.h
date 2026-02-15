/* Companion header file. */

/* Alphabetized forward declarations for core/master/valid.c */

/* Alphabetized forward declarations (ctags) for core/master/valid.c */
void create();
int get_inherit_called();
int valid_author(string str);
int valid_bind(object binder, object old_owner, object new_owner);
int valid_database(object caller, string func, mixed *info);
int valid_domain(string str);
int valid_hide(object ob);
int valid_link(string from, string to);
int valid_object(object obj);
int valid_override(string file, string efun_name, string main_file);
int valid_read(string file, mixed user, string func);
int valid_save_binary(string file);
int valid_seteuid(object obj, string euid);
int valid_shadow(object ob);
int valid_socket(object caller, string func, mixed *info);
int valid_write(string file, mixed user, string func);
