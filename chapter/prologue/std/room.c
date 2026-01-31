inherit "/core/object";

#include "room.h"
#include <room-checks.c>
#include "room-link-handling.c"

string short_desc, long_desc;

void create() {
  ::create();

  short_desc = "";
  long_desc = "";

  set_light(1);

  return;
}

string short() {
  return short_desc;
}

string long() {
  return long_desc;
}

