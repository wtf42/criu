#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/mount.h>
#include <stdlib.h>
#include "zdtmtst.h"

const char *test_doc	= "";
const char *test_author	= "";

void do_sth(void)
{
	int i, j;
	unsigned long int rnd = 42;
	for (i = 0; i < 1000 * 1000; ++i) {
		for (j = 0; j < 300; ++j) {
			rnd = 1103515245 * rnd + 12345;
		}
		//rnd = rnd * 214013L + 2531011L;
	}
	if (rnd == 0)
		exit(42);
}

int main(int argc, char **argv)
{

	test_init(argc, argv);

	test_daemon();

	while(test_go())
	{
		do_sth();
	}

	test_waitsig();

	do_sth();

	pass();

	return 0;
}
