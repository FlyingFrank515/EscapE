#include "front.h"
#include "computer.h"
#include "backpack.h"
#include "animate.h"
extern backpack item[5];
extern int backpack_count ;
extern int choosed ;
FRONT_VIEW::FRONT_VIEW()
{
	TOTAL_BUTTONS=12;
	BUTTON_DIM[0][0]=70 ,BUTTON_DIM[0][1]=150;
	BUTTON_DIM[1][0]=232,BUTTON_DIM[1][1]=182;
	BUTTON_DIM[2][0]=172,BUTTON_DIM[2][1]=53;
	BUTTON_DIM[3][0]=70 ,BUTTON_DIM[3][1]=150;
    BUTTON_DIM[4][0]=110,BUTTON_DIM[4][1]=110;
	BUTTON_DIM[5][0]=110,BUTTON_DIM[5][1]=110;
	BUTTON_DIM[6][0]=70, BUTTON_DIM[6][1]=70;
	BUTTON_DIM[7][0]=110,BUTTON_DIM[7][1]=110;
	BUTTON_DIM[8][0]=110,BUTTON_DIM[8][1]=110;
	BUTTON_DIM[9][0]=172,BUTTON_DIM[9][1]=70;
    BUTTON_DIM[10][0]=172,BUTTON_DIM[10][1]=62;
    BUTTON_DIM[11][0]=101,BUTTON_DIM[11][1]=100;

    BUTTON_POS[0][0]=0   ,BUTTON_POS[0][1]=300;//left
	BUTTON_POS[1][0]=438 ,BUTTON_POS[1][1]=302;//computer
	BUTTON_POS[2][0]=718 ,BUTTON_POS[2][1]=486;//drawer1
	BUTTON_POS[3][0]=1240,BUTTON_POS[3][1]=300;//right
    BUTTON_POS[4][0]=310 ,BUTTON_POS[4][1]=680;
	BUTTON_POS[5][0]=455 ,BUTTON_POS[5][1]=680;
	BUTTON_POS[6][0]=620 ,BUTTON_POS[6][1]=703;
	BUTTON_POS[7][0]=745 ,BUTTON_POS[7][1]=680;
	BUTTON_POS[8][0]=890 ,BUTTON_POS[8][1]=680;
    BUTTON_POS[9][0]=718 ,BUTTON_POS[9][1]=486+53;//drawer2
    BUTTON_POS[10][0]=718 ,BUTTON_POS[10][1]=486+123;//drawer3
    BUTTON_POS[11][0]=343 ,BUTTON_POS[11][1]=375; //death
}

bool FRONT_VIEW::loadMedia() {
	bool success = true;
	if(!PNG[0].loadFromFile("back_front_picture/background_front.png")) {  // you will need to modify the path in your derived classes
		printf("Failed to load Pictures background_back.png!\n");
		success = false;
	}
	if(!PNG[1].loadFromFile("back_front_picture/death.png")) {  // you will need to modify the path in your derived classes
		printf("Failed to load Pictures death.png!\n");
		success = false;
	}
	return success;
}
void FRONT_VIEW::render(void) {
	PNG[0].render(0,0);
	if(FRONT_VIEW::death) PNG[1].render(BUTTON_POS[11][0],BUTTON_POS[11][1]);
}

int FRONT_VIEW::handleEvent(SDL_Event *e, int current) {
	if(e->type == SDL_MOUSEBUTTONDOWN) {
		int x, y;
		SDL_GetMouseState( &x, &y );
		if( x > BUTTON_POS[0][0] && x < (BUTTON_POS[0][0] + BUTTON_DIM[0][0]) && y > BUTTON_POS[0][1] &&
		    y < (BUTTON_POS[0][1] + BUTTON_DIM[0][1])) {
			return 3;//left
		}
		else if( x > BUTTON_POS[1][0] && x < (BUTTON_POS[1][0] + BUTTON_DIM[1][0]) && y > BUTTON_POS[1][1] &&
		    y < (BUTTON_POS[1][1] + BUTTON_DIM[1][1])&& item[choosed].return_name() != "bottle") {
			if(Computer_Login::login) return 12;//surface
            else    return 11;//login
		}
		else if( x > BUTTON_POS[1][0] && x < (BUTTON_POS[1][0] + BUTTON_DIM[1][0]) && y > BUTTON_POS[1][1] &&
		    y < (BUTTON_POS[1][1] + BUTTON_DIM[1][1])&& item[choosed].return_name() == "bottle") {
			broken();
			return 29;
		}
		else if( x > BUTTON_POS[2][0] && x < (BUTTON_POS[2][0] + BUTTON_DIM[2][0]) && y > BUTTON_POS[2][1] &&
		    y < (BUTTON_POS[2][1] + BUTTON_DIM[2][1])) {
			return 7;//drawer1
		}
		else if( x > BUTTON_POS[3][0] && x < (BUTTON_POS[3][0] + BUTTON_DIM[3][0]) && y > BUTTON_POS[3][1] &&
		    y < (BUTTON_POS[3][1] + BUTTON_DIM[3][1])) {
			return 1;//left
		}
		else if( x > BUTTON_POS[4][0] && x < (BUTTON_POS[4][0] + BUTTON_DIM[4][0]) && y > BUTTON_POS[4][1] &&
		    y < (BUTTON_POS[4][1] + BUTTON_DIM[4][1])) {
			return current;//backpack1
		}
		else if( x > BUTTON_POS[5][0] && x < (BUTTON_POS[5][0] + BUTTON_DIM[5][0]) && y > BUTTON_POS[5][1] &&
		    y < (BUTTON_POS[5][1] + BUTTON_DIM[5][1])) {
			return current;//backpack2
		}
		else if( x > BUTTON_POS[6][0] && x < (BUTTON_POS[6][0] + BUTTON_DIM[6][0]) && y > BUTTON_POS[6][1] &&
		    y < (BUTTON_POS[6][1] + BUTTON_DIM[6][1])&&DRAWER2::paper) {
			choosed = 5;
			return 31;//backpack3
		}
		else if( x > BUTTON_POS[7][0] && x < (BUTTON_POS[7][0] + BUTTON_DIM[7][0]) && y > BUTTON_POS[7][1] &&
		    y < (BUTTON_POS[7][1] + BUTTON_DIM[7][1])) {
			return current;//backpack4
		}
		else if( x > BUTTON_POS[8][0] && x < (BUTTON_POS[8][0] + BUTTON_DIM[8][0]) && y > BUTTON_POS[8][1] &&
		    y < (BUTTON_POS[8][1] + BUTTON_DIM[8][1])) {
			return current;//backpack5
		}
		else if( x > BUTTON_POS[9][0] && x < (BUTTON_POS[9][0] + BUTTON_DIM[9][0]) && y > BUTTON_POS[9][1] &&
		    y < (BUTTON_POS[9][1] + BUTTON_DIM[9][1])) {
            return 8;//drawer2
		}
        else if( x > BUTTON_POS[10][0] && x < (BUTTON_POS[10][0] + BUTTON_DIM[10][0]) && y > BUTTON_POS[10][1] &&
		    y < (BUTTON_POS[10][1] + BUTTON_DIM[10][1])) {
			return 9;//drawer3
		}
		else if( x > BUTTON_POS[11][0] && x < (BUTTON_POS[11][0] + BUTTON_DIM[11][0]) && y > BUTTON_POS[11][1] &&
		    y < (BUTTON_POS[11][1] + BUTTON_DIM[11][1])&& item[choosed].return_name() == "bottle") {
			FRONT_VIEW::death=true;
			return current;//drawer3
        }
		else
			return current;
	}
	return current;
}
DRAWER1::DRAWER1()
{
	TOTAL_BUTTONS=1;
	BUTTON_DIM[0][0]=100 ,BUTTON_DIM[0][1]=100;
	BUTTON_POS[0][0]=0   ,BUTTON_POS[0][1]=0;
}
bool DRAWER1::loadMedia() {
	bool success = true;
    if(!PNG[1].loadFromFile("back_front_picture/drawer1.png")) {
    printf("Failed to load Pictures drawer1.png!\n");
		success = false;
	}
	else if(!PNG[0].loadFromFile("back_front_picture/back.png")) {
    printf("Failed to load Pictures back.png!\n");
		success = false;
	}
	return success;
}
void DRAWER1::render(void) {
	PNG[1].render(0,0);
	PNG[0].render(BUTTON_POS[0][0], BUTTON_POS[0][1]);
}

int DRAWER1::handleEvent(SDL_Event *e, int current) {
	if(e->type == SDL_MOUSEBUTTONDOWN) {
		int x, y;
		SDL_GetMouseState( &x, &y );
		if( x > BUTTON_POS[0][0] && x < (BUTTON_POS[0][0] + BUTTON_DIM[0][0]) && y > BUTTON_POS[0][1] &&
		    y < (BUTTON_POS[0][1] + BUTTON_DIM[0][1])) {
			return 0;
		}
		else
			return current;
	}
	return current;
}
DRAWER2::DRAWER2()
{
    paper = false;
	TOTAL_BUTTONS=1;
	BUTTON_DIM[0][0]=100 ,BUTTON_DIM[0][1]=100;
	BUTTON_POS[0][0]=0   ,BUTTON_POS[0][1]=0;
	BUTTON_DIM[1][0]=250 ,BUTTON_DIM[1][1]=140;
	BUTTON_POS[1][0]=360   ,BUTTON_POS[1][1]=330;
}
bool DRAWER2::loadMedia() {
	bool success = true;
    if(!PNG[1].loadFromFile("back_front_picture/drawer2.png")) {
    printf("Failed to load Pictures drawer1.png!\n");
		success = false;
	}
	else if(!PNG[0].loadFromFile("back_front_picture/back.png")) {
    printf("Failed to load Pictures back.png!\n");
		success = false;
	}
	else if(!PNG[2].loadFromFile("back_front_picture/paper.png")) {
    printf("Failed to load Pictures paper.png!\n");
		success = false;
	}
	return success;
}
void DRAWER2::render(void) {
	PNG[1].render(0,0);
	if(!paper) PNG[2].render(BUTTON_POS[1][0], BUTTON_POS[1][1]);
	PNG[0].render(BUTTON_POS[0][0], BUTTON_POS[0][1]);
}

int DRAWER2::handleEvent(SDL_Event *e, int current) {
	if(e->type == SDL_MOUSEBUTTONDOWN) {
		int x, y;
		SDL_GetMouseState( &x, &y );
		if( x > BUTTON_POS[0][0] && x < (BUTTON_POS[0][0] + BUTTON_DIM[0][0]) && y > BUTTON_POS[0][1] &&
		    y < (BUTTON_POS[0][1] + BUTTON_DIM[0][1])) {
			return 0;
		}
		else if( x > BUTTON_POS[1][0] && x < (BUTTON_POS[1][0] + BUTTON_DIM[1][0]) && y > BUTTON_POS[1][1] &&
		    y < (BUTTON_POS[1][1] + BUTTON_DIM[1][1])) {
            if(!paper){
                item[2].pic.loadFromFile("backpack/paper_icon.png");
                item[2].setname("paper");
                paper = true;
            }
			return current;//drawer3
		}
		else
			return current;
	}
	return current;
}
DRAWER3::DRAWER3()
{
	TOTAL_BUTTONS=1;
	BUTTON_DIM[0][0]=100 ,BUTTON_DIM[0][1]=100;
	BUTTON_POS[0][0]=0   ,BUTTON_POS[0][1]=0;
}
bool DRAWER3::loadMedia() {
	bool success = true;
    if(!PNG[1].loadFromFile("back_front_picture/drawer3.png")) {
    printf("Failed to load Pictures drawer3.png!\n");
		success = false;
	}
	else if(!PNG[0].loadFromFile("back_front_picture/back.png")) {
    printf("Failed to load Pictures back.png!\n");
		success = false;
	}
	return success;
}
void DRAWER3::render(void) {
	PNG[1].render(0,0);
	PNG[0].render(BUTTON_POS[0][0], BUTTON_POS[0][1]);
}
int DRAWER3::handleEvent(SDL_Event *e, int current) {
	if(e->type == SDL_MOUSEBUTTONDOWN) {
		int x, y;
		SDL_GetMouseState( &x, &y );
		if( x > BUTTON_POS[0][0] && x < (BUTTON_POS[0][0] + BUTTON_DIM[0][0]) && y > BUTTON_POS[0][1] &&
		    y < (BUTTON_POS[0][1] + BUTTON_DIM[0][1])) {
			return 0;
		}
		else
			return current;
	}
	return current;
}
