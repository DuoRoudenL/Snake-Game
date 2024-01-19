#include "Entity.h"

Entity::Entity(char character, int xPosition, int yPosition) {
	_character = character;
	_xPosition = xPosition;
	_yPosition = yPosition;
}

char Entity::getCharacter() {
	return _character;
}

int Entity::getXPosition() {
	return _xPosition;
}

int Entity::getYPosition() {
	return _yPosition;
}

void Entity::setXPosition(int xPosition) {
	_xPosition = xPosition;
}

void Entity::setYPosition(int yPosition) {
	_yPosition = yPosition;
}