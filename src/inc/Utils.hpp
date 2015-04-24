#ifndef __UTILS_HPP__
#define __UTILS_HPP__

#include <stdlib.h>
#include <time.h>

int	intGenerator(int from, int to) {
	srand(time(NULL));
	return (rand()%(to-from)+from);
}

#endif