#include <iostream>

#include <conio.h>

#include "Field.h"
#include "Entity.h"
#include "RoufenLibrary.h"

int main()
{
    Field field = Field(30, 30);
    int fieldHight = field.getHight();
    int fieldWidth = field.getWidth();

    Entity entity = Entity('@', fieldWidth / 2, fieldHight / 2);
    std::string entityCharactet = std::string(1, entity.getCharacter());
    int entityXPosition = entity.getXPosition();
    int entityYPosition = entity.getYPosition();

    int appleXPosition, appleYPosition;
    while (true) {
        appleXPosition = random(1, fieldWidth - 2);
        appleYPosition = random(1, fieldHight - 2);
        if (field.checkCharacter(' ', appleXPosition, appleYPosition)) {
            break;
        }
    }
    std::string appleCharacter = ".";
    Entity apple = Entity(appleCharacter[0], appleXPosition, appleYPosition);
    field.setCharacter(appleCharacter, appleXPosition, appleYPosition);

    std::vector <Entity> body;

    char button = ' ';
    int score = 0, tempXPosition, tempYPosition;

    while (button != 'q') {

        field.setCharacter(entityCharactet, entityXPosition, entityYPosition);

        for (int i = 0; i < body.size(); i++) {
            field.setCharacter(std::string(1, body[i].getCharacter()), body[i].getXPosition(), body[i].getYPosition());
        }

        field.print();
        std::cout << "Score: " << score;

        field.setCharacter(" ", entityXPosition, entityYPosition);

        tempXPosition = entityXPosition;
        tempYPosition = entityYPosition;

        button = _getch();
        switch (button) {
        case 'w':
            if (!field.checkCharacter('#', entityXPosition, entity.getYPosition() - 1)) {
                entity.setYPosition(entity.getYPosition() - 1);
            }
            break;
        case 'a':
            if (!field.checkCharacter('#', entity.getXPosition() - 1, entityYPosition)) {
                entity.setXPosition(entity.getXPosition() - 1);
            }
            break;
        case 's':
            if (!field.checkCharacter('#', entityXPosition, entity.getYPosition() + 1)) {
                entity.setYPosition(entity.getYPosition() + 1);
            }
            break;
        case 'd':
            if (!field.checkCharacter('#', entity.getXPosition() + 1, entityYPosition)) {
                entity.setXPosition(entity.getXPosition() + 1);
            }
            break;
        default:
            break;
        }

        entityXPosition = entity.getXPosition();
        entityYPosition = entity.getYPosition();

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

        if (entityXPosition == apple.getXPosition() && entityYPosition == apple.getYPosition()) {
            score++;
            while (true) {
                appleXPosition = random(1, fieldWidth - 2);
                appleYPosition = random(1, fieldHight - 2);
                if (field.checkCharacter(' ', appleXPosition, appleYPosition)) {
                    break;
                }
            }
            apple.setXPosition(appleXPosition);
            apple.setYPosition(appleYPosition);
            field.setCharacter(appleCharacter, appleXPosition, appleYPosition);
            body.push_back(Entity('@', tempXPosition, tempYPosition));
        }

        system("cls");
    }
}