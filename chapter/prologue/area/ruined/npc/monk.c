// inside NPC object
void on_player_says(object who, string msg) {
  AI_D->query_response(
    this_object(),          // npc id (can be object; broker can stringify)
    who,                    // player id
    "dialogue",
    ([
      "utterance": msg,
      "persona_id": "brother_halven_v1",
      "room_short": environment()->query_short(),
    ]),
    ([
      "max_tokens": 120,
      "style": "low-fantasy",
    ]),
    this_object(),
    "ai_reply_cb"
  );
}

void ai_reply_cb(mapping req, mixed resp, mixed err) {
  if (err) {
    // graceful fallback
    say("The monk stares past you, as if listening to some distant collapse.\n");
    return;
  }

  if (mapp(resp) && stringp(resp["text"])) {
    say(resp["text"] + "\n");
  } else {
    say("...\n");
  }
}

