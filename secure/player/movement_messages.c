/* ------------------------------------------------------------------------- */
/* Movement message settings. */

/* Sets the outbound movement message. */
int setmout(string message) {
  msgout = message;
  return 1;
}

/* Sets the inbound movement message. */
int setmin(string message) {
  msgin = message;
  return 1;
}

/* Sets the magic outbound movement message. */
int setmmout(string message) {
  mmsgout = message;
  return 1;
}

/* Sets the magic inbound movement message. */
int setmmin(string message) {
  mmsgin = message;
  return 1;
}

/* Displays current movement messages. */
int review() {
  write("mout:\t" + msgout + "\nmin:\t" + msgin + "\nmmout:\t" + mmsgout +
        "\nmmin:\t" + mmsgin + "\n");
  return 1;
}

/* Returns the inbound movement message. */
string query_msgin() {
  return msgin;
}

/* Returns the outbound movement message. */
string query_msgout() {
  return msgout;
}

/* Returns the magic inbound movement message. */
string query_mmsgin() {
  return mmsgin;
}

/* Returns the magic outbound movement message. */
string query_mmsgout() {
  return mmsgout;
}
