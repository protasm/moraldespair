// /daemon/AI_d.h
//
// Forward declarations for AI_d.c
// Plain-mode, strong-types friendly
//

#pragma strong_types
#pragma save_types

/* =========================================================
 * Public API
 * ========================================================= */

/*
 * High-level query entry point (future narrative layer)
 * (May be implemented later)
 */
public int query_response(
    mixed npc_id,
    mixed player_id,
    string event,
    mapping context,
    mapping options,
    object cb_obj,
    string cb_func
);

/*
 * Convenience wrapper (future)
 */
public int say_to_npc(
    object npc,
    object player,
    string utterance,
    object cb_obj,
    string cb_func
);

/*
 * Low-level ERQ-backed query (IMPLEMENTED)
 */
public int query(
    string prompt,
    object cb_obj,
    string cb_func
);

/*
 * Introspection
 */
public mapping req_status();

/* =========================================================
 * ERQ callbacks (IMPLEMENTED)
 * ========================================================= */

private void tcp_open_cb(int *reply, int id);
private void tcp_read_cb(mixed msg, int id);

/* =========================================================
 * Result handling (IMPLEMENTED)
 * ========================================================= */

private void deliver(mapping req);
private void fail(mapping req, string msg);
private void cleanup(int id);

