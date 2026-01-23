string board_short;
string board_long;
string input_prompt;
string save_file;
mapping *messages;
mapping pending_writes;

int do_erase(string str);
int do_read(string str);
int do_write(string str);
void finalize_message(object writer, mapping data);
string format_est_date(int timestamp);
void list_titles();
void receive_line(string line, object writer);

void create() {
  board_short = "a bulletin board";
  board_long = "A battered board of dark wood hangs against the wall.\n";
  input_prompt = "]";
  save_file = "/chapter/prologue/area/ruined/item/lounge_board_save";
  messages = ({});
  pending_writes = ([]);

  restore_object(save_file);

  if (!messages)
    messages = ({});

  if (!pending_writes)
    pending_writes = ([]);

  return;
}

int id(string str) {
  return str == "board" || str == "bulletin board" || str == "bulletin";
}

string short() {
  return board_short;
}

void long() {
  write(board_long);
  list_titles();
  write("Use 'write <title>', 'read <#>', and 'erase <#>' to use the board.\n");

  return;
}

int get() {
  return 0;
}

void init() {
  add_action("do_write", "write");
  add_action("do_read", "read");
  add_action("do_erase", "erase");

  return;
}

void list_titles() {
  int index;
  int total;
  mapping entry;
  string date;

  total = sizeof(messages);

  if (!total) {
    write("The board is empty.\n");
    return;
  }

  write("Posted messages:\n");

  index = 0;
  while (index < total) {
    entry = messages[index];
    date = format_est_date(entry["time"]);

    write((index + 1) + ") " + entry["title"] + " (" + date + ")\n");
    index += 1;
  }

  return;
}

int do_read(string str) {
  int number;
  mapping entry;
  string date;

  if (!str || str == "board" || str == "bulletin board" || str == "bulletin") {
    list_titles();
    return 1;
  }

  if (sscanf(str, "%d", number) != 1) {
    write("Read which message?\n");
    return 1;
  }

  if (number < 1 || number > sizeof(messages)) {
    write("That message does not exist.\n");
    return 1;
  }

  entry = messages[number - 1];
  date = format_est_date(entry["time"]);

  write("Title: " + entry["title"] + "\n");
  write("By: " + entry["name"] + "\n");
  write("Date: " + date + "\n\n");
  write(entry["body"]);

  return 1;
}

int do_write(string str) {
  string title;

  if (!str) {
    write("Write what title?\n");
    return 1;
  }

  if (sscanf(str, "board %s", title) == 1)
    str = title;

  if (str == "board" || str == "bulletin board" || str == "bulletin") {
    write("Write what title?\n");
    return 1;
  }

  if (pending_writes[this_player()]) {
    write("You are already writing a message.\n");
    return 1;
  }

  pending_writes[this_player()] = ([
    "title" : str,
    "lines" : ({ })
  ]);

  write("Enter your message.\n");
  write("End with ** on a new line.\n");

  input_to("receive_line", 0, this_player(), input_prompt);

  return 1;
}

void receive_line(string line, object writer) {
  mapping data;
  string *lines;

  if (!writer)
    return;

  data = pending_writes[writer];

  if (!data) {
    write("You are not writing a message.\n");
    return;
  }

  if (line == "**") {
    finalize_message(writer, data);
    return;
  }

  lines = data["lines"];
  lines += ({ line });
  data["lines"] = lines;
  pending_writes[writer] = data;

  input_to("receive_line", 0, writer, input_prompt);

  return;
}

string format_est_date(int timestamp) {
  int adjusted;
  int *parts;
  string *days;
  string *months;
  string result;

  adjusted = timestamp - (5 * 60 * 60);
  parts = gmtime(adjusted);
  days = ({ "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" });
  months = ({ "Jan", "Feb", "Mar", "Apr", "May", "Jun",
              "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" });
  result = sprintf("%s %s %02d %02d:%02d:%02d %04d EST",
                   days[parts[6]],
                   months[parts[4]],
                   parts[3],
                   parts[2],
                   parts[1],
                   parts[0],
                   parts[5]);

  return result;
}

void finalize_message(object writer, mapping data) {
  string *lines;
  string body;
  mapping entry;

  lines = data["lines"];

  if (!sizeof(lines)) {
    write("No message entered.\n");
    pending_writes = m_delete(pending_writes, writer);
    return;
  }

  body = implode(lines, "\n") + "\n";
  entry = ([
    "title" : data["title"],
    "body" : body,
    "name" : writer->query_name(),
    "user" : writer->query_real_name(),
    "time" : time()
  ]);

  messages += ({ entry });
  pending_writes = m_delete(pending_writes, writer);
  save_object(save_file);

  write("Message posted.\n");
  tell_room(environment(this_object()),
            writer->query_name() + " writes on the bulletin board.\n",
            ({ writer }));

  return;
}

int do_erase(string str) {
  int number;
  mapping entry;
  string author;

  if (!str) {
    write("Erase which message?\n");
    return 1;
  }

  if (sscanf(str, "%d", number) != 1) {
    write("Erase which message?\n");
    return 1;
  }

  if (number < 1 || number > sizeof(messages)) {
    write("That message does not exist.\n");
    return 1;
  }

  entry = messages[number - 1];
  author = entry["user"];

  if (author != this_player()->query_real_name()) {
    write("You may only erase your own messages.\n");
    return 1;
  }

  messages = messages[0..number - 2] + messages[number..];
  save_object(save_file);

  write("Message erased.\n");
  tell_room(environment(this_object()),
            this_player()->query_name() + " erases a message from the board.\n",
            ({ this_player() }));

  return 1;
}
