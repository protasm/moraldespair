/* Companion header file. */

/* Alphabetized forward declarations for core/avatar/avatar-data.c */

/* Alphabetized forward declarations (ctags) for core/avatar/avatar-data.c */
object account();
int brief();
string current_chapter();
string display_name();
int ensure_player_level(mapping player_data);
int is_wizard();
int last_played();
mapping load_player_data();
string name();
string normalize_key(string value);
mixed parse_json(string raw);
object player();
string player_file_path();
int query_level();
string read_json_file(string file);
int save_player_data(mapping player_data);
string short();
string short_for(object observer);
mapping soul_emote(string verb);
mapping soul_emotes();
string soul_emotes_path();
void set_account(object new_account);
int set_brief(int state);
int set_current_chapter(string chapter_id);
int set_display_name(string new_display_name);
int set_level(int new_level);
int set_last_played(int last_played);
void set_name(string new_name);
void set_player(object player);
void set_sensory_profile(mapping profile_override);
int set_sensory_form(string new_form);
int set_unlocked_chapters(string *chapter_ids);
mapping sensory_profile();
string sensory_form();
int toggle_brief();
int unlock_chapter(string chapter_id);
string *unlocked_chapters();
