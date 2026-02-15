/* Companion header file. */

/* Alphabetized forward declarations for core/object/object.c */
varargs void create(mixed args...);

/* Alphabetized forward declarations (ctags) for core/object/object.c */
int clean_up(int inherited);
varargs void create(mixed args...);
void heart_beat();
int id(string an_id);
void init();
int is_living();
int move(mixed dest);
void move_or_destruct(object dest);
void on_destruct();
void remove();
void reset();
void virtual_start();
