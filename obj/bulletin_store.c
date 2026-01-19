string messages;
string save_file;
int num_messages;

mapping restore_board() {
  mapping data;

  if (!save_file)
    save_file = "/domain/original/item/bulletin";

  messages = "";
  num_messages = 0;

  restore_object(save_file);

  data = ([
    "messages": messages,
    "num_messages": num_messages,
  ]);

  return data;
}

void save_board(string new_messages, int new_num_messages) {
  if (!save_file)
    save_file = "/domain/original/item/bulletin";

  messages = new_messages;
  num_messages = new_num_messages;

  save_object(save_file);

  return;
}

void create() {
  save_file = "/domain/original/item/bulletin";

  return;
}
