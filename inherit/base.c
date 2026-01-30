// set to 'private static' so that inheritor won't be able to directly
// access this variable and so that save_object() won't save it to the .o file

//private static string *ids;

void set_ids(string *arg) {
  // probably want to add some security here.
//  ids = arg;
}

int id(string arg) {
//  if (!arg || !ids)
//    return 0;

//  return (member_array(arg, ids) != -1);
}
