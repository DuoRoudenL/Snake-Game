#pragma once

class Entity
{
private:
	char _character;
	int _xPosition, _yPosition;
public:
	Entity(char character, int xPosition, int yPosition);
	char getCharacter();
	int getXPosition();
	int getYPosition();
	void setXPosition(int xPosition);
	void setYPosition(int yPosition);
};