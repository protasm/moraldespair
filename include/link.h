#ifndef _LINK_H
#define _LINK_H

/****************************************************************************
 * Link traversal outcomes
 *
 * Outcome describes the spatial result of a traversal attempt.
 * Mutations, cost, and narration are orthogonal and may accompany
 * ANY outcome.
 ****************************************************************************/

/* Traversal denied; actor remains in origin */
#define LINK_OUTCOME_DENY            0

/* Traversal succeeded normally */
#define LINK_OUTCOME_ALLOW           1

/* Traversal succeeded, then actor was forced back to origin */
#define LINK_OUTCOME_ALLOW_REVERSE   2

/* Traversal succeeded, then actor was redirected elsewhere */
#define LINK_OUTCOME_ALLOW_REDIRECT  3


/****************************************************************************
 * Link result mapping keys
 *
 * A traversal attempt returns a mapping with some or all of these keys.
 ****************************************************************************/

/*
 * Required:
 *   One of LINK_OUTCOME_* above.
 */
#define LINK_RESULT_OUTCOME          "outcome"

/*
 * Optional:
 *   Actor-facing message describing link- or gate-owned events.
 *   (Rooms/actors narrate their own agency separately.)
 */
#define LINK_RESULT_MESSAGE          "message"

/*
 * Optional:
 *   String destination for redirects (ALLOW_REDIRECT only).
 */
#define LINK_RESULT_REDIRECT         "redirect"

/*
 * Optional:
 *   Environment object representing the intermediate destination
 *   reached before a redirect (for trapdoors, chutes, etc.).
 */
#define LINK_RESULT_INTERMEDIATE     "intermediate"

/*
 * Optional:
 *   Traversal cost (e.g., stamina, fatigue, time).
 *   Interpretation is game-specific.
 */
#define LINK_RESULT_COST             "cost"

/*
 * Optional:
 *   Side effects / mutations applied as a result of traversal.
 *   May be a mapping or an array, depending on your effect system.
 *
 * Examples:
 *   ([ "stamina" : -3 ])
 *   ({ ([ "type":"damage", "amount":5 ]) })
 */
#define LINK_RESULT_MUTATIONS        "mutations"

#endif /* _LINK_H */

