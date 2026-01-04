#include "std.h"

int reboot_time, time_from_reset, last_reset_cycle;
int list_length;

void reset(string arg)
{
    if (time_from_reset)
	last_reset_cycle = time() - time_from_reset;
    time_from_reset = time();
    if (arg)
	return;
    set_light(1);
    reboot_time = time();
}

void init()
{
}

string short() {
    return "Sanctuary";
}

void long(string str)
{
    if (str == "clock") {
	int i, j;
	write("The clock shows ");
	i = time() - reboot_time;
	j = i / 60 / 60 / 24;
	if (j == 1)
	    write("1 day ");
	else if (j > 0)
	    write(j + " days ");
	i -= j * 60 * 60 * 24;
	j = i / 60 / 60;
	if (j == 1)
	    write("1 hour ");
	else if (j > 0)
	    write(j + " hours ");
	i -= j * 60 * 60;
	j = i / 60;
	if (j == 1)
	    write("1 minute ");
	else if (j > 0)
	    write(j + " minutes ");
	i -= j * 60;
	if (i == 1)
	    write("1 second");
	else if (i > 0)
	    write(i + " seconds");
	write("\n");
	if (this_player()->query_level() < 20)
	    return;
	write("Time since reset is " + (time() - time_from_reset) +
	      " seconds.\n");
	if (last_reset_cycle)
	    write("Reset cycle: " + last_reset_cycle + "\n");
	write("Free block list length: " + list_length + "\n");
	return;
    }
    write("The Sanctuary.\n");
    write("There is a clock on the wall.\n");

}

int id(string str) {
    return str == "clock";
}
