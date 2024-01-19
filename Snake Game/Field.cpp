#include "Field.h"

Field::Field(int width, int hight) {
	std::string border = "", space = "";
	for (int i = 0; i < width; i++) {
		border += "#";
		space += " ";
	}
	space.replace(0, 1, "#");
	space.replace(space.size() - 1, 1, "#");
	_field.push_back(border);
	for (int i = 1; i < hight - 1; i++) {
		_field.push_back(space);
	}
	_field.push_back(border);
}

int Field::getWidth() {
	return _field[0].size();
}

int Field::getHight() {
	return _field.size();
}

void Field::setCharacter(std::string character, int xPosition, int yPosition) {
	_field[yPosition].replace(xPosition, 1, character);
}

bool Field::checkCharacter(char character, int xPosition, int yPosition) {
	return _field[yPosition][xPosition] == character;
}

void Field::print() {
	for (int i = 0; i < _field.size(); i++) {
		std::cout << _field[i] << std::endl;
	}
}