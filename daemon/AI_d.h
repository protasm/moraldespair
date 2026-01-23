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

public int query_response(
  mixed npc_id,
  mixed player_id,
  string event,
  mapping context,
  mapping options,
  object cb_obj,
  string cb_func
);

public int query(
  string prompt,
  object cb_obj,
  string cb_func
);

public mapping req_status();
