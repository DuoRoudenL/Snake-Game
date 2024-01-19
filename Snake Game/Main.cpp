#include <iostream>
#include <ctime>

#include <conio.h>

#include "Field.h"
#include "Entity.h"

int main()
{
    srand(time(NULL));

    Field field = Field(30, 30);
    int fieldHight = field.getHight();
    int fieldWidth = field.getWidth();

    Entity entity = Entity('@', fieldWidth / 2, fieldHight / 2);
    std::string entityCharactet = std::string(1, entity.getCharacter());
    int entityXPosition = entity.getXPosition();
    int entityYPosition = entity.getYPosition();

    int appleXPosition, appleYPosition;
    while (true) {
        appleXPosition = 1 + rand() % (fieldWidth - 3 + 1);
        appleYPosition = 1 + rand() % (fieldHight - 3 + 1);
        if (!(appleXPosition == entityXPosition && appleYPosition == entityYPosition)) {
            break;
        }
    }
    std::string appleCharacter = ".";
    Entity apple = Entity(appleCharacter[0], appleXPosition, appleYPosition);
    field.setCharacter(appleCharacter, appleXPosition, appleYPosition);

    char button = ' ';
    int score = 0;

    while (button != 'q') {

        field.setCharacter(entityCharactet, entityXPosition, entityYPosition);
        field.print();
        std::cout << "Score: " << score;

        field.setCharacter(" ", entityXPosition, entityYPosition);

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

        if (entityXPosition == apple.getXPosition() && entityYPosition == apple.getYPosition()) {
            score++;
            while (true) {
                appleXPosition = 1 + rand() % (fieldWidth - 3 + 1);
                appleYPosition = 1 + rand() % (fieldHight - 3 + 1);
                if (!(appleXPosition == entityXPosition && appleYPosition == entityYPosition)) {
                    break;
                }
            }
            apple.setXPosition(appleXPosition);
            apple.setYPosition(appleYPosition);
            field.setCharacter(appleCharacter, appleXPosition, appleYPosition);
        }
        
        system("cls");
    }
}