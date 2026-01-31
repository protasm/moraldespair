inherit "/chapter/prologue/std/room";

#include <globals.h>
#include <link.h>

object guard;

void create() {
  ::create();

  short_desc = "Guard Room";
  long_desc =
    "A cramped chamber just outside the prison cells. A battered table sits\n"
    "against the wall beside a sputtering lantern. The air smells of oil,\n"
    "sweat, and old iron. The cells lie to the west.\n";

  set_light(1);

  /*
   * Discover the shared Link.
   * Same Link object as the cell uses.
   */
  add_link("west", LINK_D->get_link(
    base_name(this_object()),
    "/area/prison/cell"
  ));
}

/*
 * Room-owned post-entry reaction.
 * Guard may intercept and throw the actor back.
 */
mapping link_on_enter(object actor, object origin, object link) {
  /* No guard, no problem */
  if (!objectp(guard))
    return ([ LINK_RESULT_OUTCOME : LINK_OUTCOME_ALLOW ]);

  /* Guard asleep? Let them pass. */
  if (guard->query_state("asleep"))
    return ([ LINK_RESULT_OUTCOME : LINK_OUTCOME_ALLOW ]);

  /* Guard intercepts */
  tell_object(actor,
    "The guard lunges forward and grabs you, hurling you back into the cell!\n");

  tell_room(this_object(),
    "The guard seizes " + actor->query_cap_name() +
    " and throws them back into the cell.\n",
    ({ actor }));

  return ([
    LINK_RESULT_OUTCOME   : LINK_OUTCOME_ALLOW_REVERSE,
    LINK_RESULT_MUTATIONS : ([ "hp" : -2 ])  /* optional */
  ]);
}

