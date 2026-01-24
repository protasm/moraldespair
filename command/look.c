#include <command.h>

#ifdef __NO_ENVIRONMENT__
#define say(x) shout(x)
#endif

int main(string arg) {
  say(
    (string)previous_object()->query_name()
    + " says: " +  arg + "\n"
  );

  tell_object(this_player(), "foo");
  
  return 1;
}
