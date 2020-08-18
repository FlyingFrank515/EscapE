#include "menu.h"
#include "animate.h"
MENU::MENU()
{
	TOTAL_BUTTONS=2;
	BUTTON_DIM[0][0]=583 ,BUTTON_DIM[0][1]=146;
    BUTTON_POS[0][0]=398   ,BUTTON_POS[0][1]=528;
    BUTTON_DIM[1][0]=200 ,BUTTON_DIM[1][1]=200;
    BUTTON_POS[1][0]=1110   ,BUTTON_POS[1][1]=594;
}
bool MENU::loadMedia() {
	bool success = true;
	if(!PNG[0].loadFromFile("story/menu.png")) {  // you will need to modify the path in your derived classes
		printf("Failed to load Pictures menu.png!\n");
		success = false;
	}
	if(!PNG[1].loadFromFile("story/icon.png")) {  // you will need to modify the path in your derived classes
		printf("Failed to load Pictures icon.png!\n");
		success = false;
	}
	return success;
}
void MENU::render(void) {
	PNG[0].render(0,0);
	PNG[1].render(BUTTON_POS[1][0],BUTTON_POS[1][1]);
}

int MENU::handleEvent(SDL_Event *e, int current) {
	if(e->type == SDL_MOUSEBUTTONDOWN) {
		int x, y;
		SDL_GetMouseState( &x, &y );
		if( x > BUTTON_POS[0][0] && x < (BUTTON_POS[0][0] + BUTTON_DIM[0][0]) && y > BUTTON_POS[0][1] &&
		    y < (BUTTON_POS[0][1] + BUTTON_DIM[0][1])) {
            begin();
            return 0;//front
		}
		else if( x > BUTTON_POS[1][0] && x < (BUTTON_POS[1][0] + BUTTON_DIM[1][0]) && y > BUTTON_POS[1][1] &&
		    y < (BUTTON_POS[1][1] + BUTTON_DIM[1][1])) {
            return 30;//instruction
		}
		else
			return current;
	}
	return current;
}
INSTRUCTION::INSTRUCTION()
{
	TOTAL_BUTTONS=1;
	BUTTON_DIM[0][0]=100 ,BUTTON_DIM[0][1]=100;
    BUTTON_POS[0][0]=0   ,BUTTON_POS[0][1]=0;
}
bool INSTRUCTION::loadMedia() {
	bool success = true;
	if(!PNG[0].loadFromFile("back_front_picture/back.png")) {  // you will need to modify the path in your derived classes
		printf("Failed to load Pictures back.png!\n");
		success = false;
	}
	if(!PNG[1].loadFromFile("story/instruction.png")) {  // you will need to modify the path in your derived classes
		printf("Failed to load Pictures instruction.png!\n");
		success = false;
	}
	return success;
}
void INSTRUCTION::render(void) {
	PNG[1].render(0,0);
	PNG[0].render(0,0);
}

int INSTRUCTION::handleEvent(SDL_Event *e, int current) {
	if(e->type == SDL_MOUSEBUTTONDOWN) {
		int x, y;
		SDL_GetMouseState( &x, &y );
		if( x > BUTTON_POS[0][0] && x < (BUTTON_POS[0][0] + BUTTON_DIM[0][0]) && y > BUTTON_POS[0][1] &&
		    y < (BUTTON_POS[0][1] + BUTTON_DIM[0][1])) {
            return 29;
		}
		else
			return current;
	}
	return current;
}

