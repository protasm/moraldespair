/*
 * Master Summary:
 * Purpose:
 *   Implements the object behavior defined in core/mfun/mfun.c.
 * Approach:
 *   Uses explicit LPC methods with straightforward control flow so
 *   behavior stays predictable, debuggable, and easy to evolve.
 * Dependencies:
 *   - #include "file-handling.c"
 *   - #include "text-handling.c"
 */

#include "file-handling.c"
#include "text-handling.c"

/****************************************************************************
 * Generic containment test.
 *
 * Arrays:   returns index (>=0) or -1
 * Mappings: returns 1 if key exists, 0 otherwise
 ****************************************************************************/
/* Method Summary:
 * Purpose:
 *   Handles member for this object.
 * Parameters:
 *   - mixed container, mixed item
 * Approach:
 *   Validates inputs and executes explicit local logic for member.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   int result from member.
 */
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

/* Method Summary:
 * Purpose:
 *   Handles is_member for this object.
 * Parameters:
 *   - mixed container, mixed item
 * Approach:
 *   Validates inputs and executes explicit local logic for is_member.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   int result from is_member.
 */
int is_member(mixed container, mixed item) {
  int result;

  result = member(container, item) != -1;

  return result;
}

/* Method Summary:
 * Purpose:
 *   Handles directions for this object.
 * Parameters:
 *   - none
 * Approach:
 *   Validates inputs and executes explicit local logic for directions.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   string result from directions.
 */
string *directions() {
  return ({
    "north","south","east","west",
    "northeast", "northwest", "southeast", "southwest",
    "up","down","in","out"
  });
}

/* Method Summary:
 * Purpose:
 *   Handles is_direction for this object.
 * Parameters:
 *   - string str
 * Approach:
 *   Validates inputs and executes explicit local logic for is_direction.
 * Side effects:
 *   May mutate object state and may call collaborators or perform I/O
 *   depending on runtime conditions.
 * Returns:
 *   int result from is_direction.
 */
int is_direction(string str) {
  int result;

  result = is_member(directions(), str);

  return result;
}
