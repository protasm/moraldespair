/*
 * Master Summary:
 * Purpose:
 *   Implements the object behavior defined in core/master/master.c.
 * Approach:
 *   Uses explicit LPC methods with straightforward control flow so
 *   behavior stays predictable, debuggable, and easy to evolve.
 * Dependencies:
 *   - #include <globals.h>
 *   - #include "valid.c"
 *   - #include "master-applies.c"
 */

#include <globals.h>

#include "valid.c"
#include "master-applies.c"
