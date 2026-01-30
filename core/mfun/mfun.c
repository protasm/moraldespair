#include "file-handling.c"
#include "text-handling.c"

/****************************************************************************
 * Generic containment test.
 *
 * Arrays:   returns index (>=0) or -1
 * Mappings: returns 1 if key exists, 0 otherwise
 ****************************************************************************/
int member(mixed container, mixed item) {
    // Array membership
    if (arrayp(container)) {
        // [EFUN] member_array()
        return member_array(item, container);
    }

    // Mapping membership
    if (mapp(container)) {
        return member_array(keys(container), item);
    }

    error("member(): unsupported container type\n");
}

int is_member(mixed container, mixed item) {
  return member(container, item) != -1;
}

string *query_directions() {
  return ({
    "north","south","east","west",
    "northeast", "northwest", "southeast", "southwest",
    "up","down","in","out"
  });
}

int is_direction(string str) {
  return is_member(query_directions(), str);
}

