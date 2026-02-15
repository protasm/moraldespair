string normalize_id(string value);
string normalize_path(string path);
void register_chapter(string id, string title, string description, string root, string start_room);
void create();
int chapter_exists(string id);
string latest_chapter();
string get_chapter_root(string id);
string get_start_room(string id);
int can_player_access(object player, string id);
string resolve_player_chapter(object player);
string resolve_player_start_room(object player);

/* Alphabetized forward declarations for core/daemon/chapter_d.c */

/* Alphabetized forward declarations (ctags) for core/daemon/chapter_d.c */
int can_player_access(object player, string id);
int chapter_exists(string id);
void create();
string get_chapter_root(string id);
string get_start_room(string id);
string latest_chapter();
string normalize_id(string value);
string normalize_path(string path);
void register_chapter(string id, string title, string description,
                      string root, string start_room);
string resolve_player_chapter(object player);
string resolve_player_start_room(object player);
