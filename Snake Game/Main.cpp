#include <iostream>

#include <conio.h>
#include <windows.h>

#include "Field.h"
#include "Entity.h"
#include "RoufenLibrary.h"

int main() {
    int fieldWidth = 30, fieldHight = 30;
    Field field = Field(fieldWidth, fieldHight);

    char entityCharacter = 'o';
    int entityXPosition = fieldWidth / 2, entityYPosition = fieldHight / 2;
    Entity entity = Entity(entityCharacter, entityXPosition, entityYPosition);

    char appleCharacter = '*';
    int appleXPosition, appleYPosition;
    while (true) {
        appleXPosition = random(2, fieldWidth - 3);
        appleYPosition = random(2, fieldHight - 3);
        bool isSpaceCollision = field.checkCharacter(' ', appleXPosition, appleYPosition);
        bool isBodyCollision = field.checkCharacter(entityCharacter, appleYPosition, appleYPosition);
        if (isSpaceCollision && !isBodyCollision) break;
    }
    Entity apple = Entity(appleCharacter, appleXPosition, appleYPosition);
    field.setCharacter(std::string(1, appleCharacter), appleXPosition, appleYPosition);

    std::vector <Entity> body;

    char direction = ' ';
    int score = 0, tempXPosition, tempYPosition;

    while (!GetAsyncKeyState('Q')) {
        system("cls");
        
        field.setCharacter(std::string(1, entityCharacter), entityXPosition, entityYPosition);
        for (int i = 0; i < body.size(); i++) {
            field.setCharacter(std::string(1, body[i].getCharacter()), body[i].getXPosition(), body[i].getYPosition());
        }

        field.print();
        std::cout << "Score: " << score;

        field.setCharacter(" ", entityXPosition, entityYPosition);

        tempXPosition = entityXPosition;
        tempYPosition = entityYPosition;

        if (GetAsyncKeyState('W')) direction = 'w';
        else if (GetAsyncKeyState('A')) direction = 'a';
        else if (GetAsyncKeyState('S')) direction = 's';
        else if (GetAsyncKeyState('D')) direction = 'd';
        userInputController(direction, entity);
 
        entityXPosition = entity.getXPosition();
        entityYPosition = entity.getYPosition();

        if (entityXPosition == appleXPosition && entityYPosition == appleYPosition) {
            score++;
            while (true) {
                appleXPosition = random(2, fieldWidth - 3);
                appleYPosition = random(2, fieldHight - 3);
                bool isSpaceCollision = field.checkCharacter(' ', appleXPosition, appleYPosition);
                if (isSpaceCollision) break;
            }
            apple.setXPosition(appleXPosition);
            apple.setYPosition(appleYPosition);
            field.setCharacter(std::string(1, appleCharacter), appleXPosition, appleYPosition);
            body.push_back(Entity(entityCharacter, tempXPosition, tempYPosition));
        }

        bool isWallColision = field.checkCharacter('#', entityXPosition, entityYPosition);
        bool isBodyColision = field.checkCharacter(entityCharacter, entityXPosition, entityYPosition);
        if (isWallColision || isBodyColision) {
            std::cout << std::endl << "Game Over!";
            break;
        }

        for (int i = body.size() - 1; i >= 0; i--) {
            field.setCharacter(" ", body[i].getXPosition(), body[i].getYPosition());
            if (i == 0) {
                body[i].setXPosition(tempXPosition);
                body[i].setYPosition(tempYPosition);
            }
            else {
                body[i].setXPosition(body[i - 1].getXPosition());
                body[i].setYPosition(body[i - 1].getYPosition());
            }
        }

        int speed = 30;
        Sleep(speed);
    }
}