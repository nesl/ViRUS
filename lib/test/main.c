#include "testlib.h"
#include <unistd.h>

int main() {

	int a = 100;
	{
		f(a);
		sleep(2);
	}
	return 0;
}
