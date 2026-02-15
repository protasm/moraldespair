/* Companion header file. */

/* Alphabetized forward declarations for core/player/player-data.c */

/* Alphabetized forward declarations (ctags) for core/player/player-data.c */
object account();
int brief();
string current_chapter();
string display_name();
int is_wizard();
int last_played();
mapping load_player_data();
string name();
string normalize_key(string value);
object player();
string player_file_path();
int save_player_data(mapping player_data);
void set_account(object new_account);
int set_brief(int state);
int set_current_chapter(string chapter_id);
int set_display_name(string new_display_name);
int set_last_played(int last_played);
void set_name(string new_name);
void set_player(object player);
int set_unlocked_chapters(string *chapter_ids);
int toggle_brief();
int unlock_chapter(string chapter_id);
string *unlocked_chapters();
