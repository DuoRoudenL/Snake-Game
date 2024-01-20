#include "RoufenLibrary.h"

int random(int min, int max) {
	srand(time(NULL));
	return min + rand() % (max - min + 1);
}

void userInputController(char direction, Entity &entity) {
    switch (direction) {
    case 'w':
        entity.setYPosition(entity.getYPosition() - 1);
        break;
    case 'a':
        entity.setXPosition(entity.getXPosition() - 1);
        break;
    case 's':
        entity.setYPosition(entity.getYPosition() + 1);
        break;
    case 'd':
        entity.setXPosition(entity.getXPosition() + 1);
        break;
    default:
        break;
    }
}