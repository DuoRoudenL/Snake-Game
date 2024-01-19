#include <iostream>

#include <conio.h>

#include "Field.h"
#include "Entity.h"

int main()
{
    Field field = Field(30, 30);
    int fieldHight = field.getHight();
    int fieldWidth = field.getWidth();

    Entity entity = Entity('@', fieldWidth / 2, fieldHight / 2);
    std::string entityCharactet = std::string(1, entity.getCharacter());
    int entityXPosition = entity.getXPosition();
    int entityYPosition = entity.getYPosition();

    char button = ' ';

    while (button != 'q') {
        
        field.setCharacter(entityCharactet, entityXPosition, entityYPosition);
        field.print();

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
        
        system("cls");
    }
}