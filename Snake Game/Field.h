#pragma once

#include <iostream>
#include <vector>
#include <string>

class Field
{
private:
	 std::vector <std::string> _field;
public:
	Field(int width, int hidth);
	int getWidth();
	int getHight();
	void setCharacter(std::string character, int xPosition, int yPosition);
	bool checkCharacter(char character, int xPosition, int yPosition);
	void print();
};