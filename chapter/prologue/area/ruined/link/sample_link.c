inherit "/core/link";

#define SIDE_A 0
#define SIDE_B 1

object build_gate(string gate_id) {
  object gate;

  if (!stringp(gate_id) || gate_id == "")
    return 0;

  if (gate_id == "latch_one_side") {
    gate = new("/core/gate_door");

    gate->set_name("latch");
    gate->set_block_message(SIDE_A, "The latch is locked from this side.");
    gate->set_block_message(SIDE_B, "The latch is shut.");
    gate->set_lock_id(SIDE_A, "demo");
    gate->set_locked_state(SIDE_A, 1);
    gate->set_open_state(SIDE_A, 0);
    gate->set_open_state(SIDE_B, 0);

    return gate;
  }

  if (gate_id == "hatch_basic") {
    gate = new("/core/gate_door");

    gate->set_name("hatch");
    gate->set_block_message(SIDE_A, "The hatch is shut.");
    gate->set_block_message(SIDE_B, "The hatch is shut.");
    gate->set_open_state(SIDE_A, 0);
    gate->set_open_state(SIDE_B, 0);

    return gate;
  }

  if (gate_id == "rubble_door_near") {
    gate = new("/core/gate_door");

    gate->set_name("door");
    gate->set_block_message(SIDE_A, "The nearer door is closed.");
    gate->set_block_message(SIDE_B, "The nearer door is closed.");
    gate->set_open_state(SIDE_A, 0);
    gate->set_open_state(SIDE_B, 0);

    return gate;
  }

  if (gate_id == "rubble_door_far") {
    gate = new("/core/gate_door");

    gate->set_name("door");
    gate->set_block_message(SIDE_A, "The farther door is closed.");
    gate->set_block_message(SIDE_B, "The farther door is closed.");
    gate->set_open_state(SIDE_A, 0);
    gate->set_open_state(SIDE_B, 0);

    return gate;
  }

  return 0;
}

void add_gate_id(string gate_id) {
  object gate;

  gate = build_gate(gate_id);

  if (!objectp(gate))
    return;

  add_gate(gate);
}
