/* Companion header file. */

/* Alphabetized forward declarations for core/player/player.c */

/* Alphabetized forward declarations (ctags) for core/player/player.c */
string abbreviate_exit(string direction);
void catch_tell(string message);
void check_wizard();
void create();
string endpoint_id_for_room(object room);
void gmcp(string message);
void gmcp_enable(int enabled);
void heart_beat();
int is_living();
void logon();
void msdp(string message);
void msdp_enable(int enabled);
void msp_enable(int enabled);
void mxp_enable(int enabled);
void mxp_tag(string message);
void net_dead();
void receive_ed(string message);
void receive_environ(string message);
void receive_snoop(string message);
void show_location(int force_verbose, int show_path);
void telnet_suboption(int option, string message);
void terminal_colour_replace(string message);
void terminal_type(string message);
void window_size(int width, int height);
void write_prompt();
void zmp(string message);
