/* Companion header file. */

/* Alphabetized forward declarations for core/player/player.c */
object avatar();
void catch_tell(string message);
void check_wizard();
void create();
void deliver_experience(mapping event);
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
void set_avatar(object new_avatar);
void show_location(int force_verbose, int show_path);
void telnet_suboption(int option, string message);
void terminal_colour_replace(string message);
void terminal_type(string message);
void window_size(int width, int height);
void write_prompt();
void zmp(string message);

/* Alphabetized forward declarations (ctags) for core/player/player.c */
object avatar();
void catch_tell(string message);
void check_wizard();
void create();
void deliver_experience(mapping event);
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
void set_avatar(object new_avatar);
void show_location(int force_verbose, int show_path);
void telnet_suboption(int option, string message);
void terminal_colour_replace(string message);
void terminal_type(string message);
void window_size(int width, int height);
void write_prompt();
void zmp(string message);
