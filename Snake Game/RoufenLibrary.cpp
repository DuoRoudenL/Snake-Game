#include "RoufenLibrary.h"

int random(int min, int max) {
	srand(time(NULL));
	return min + rand() % (max - min + 1);
}