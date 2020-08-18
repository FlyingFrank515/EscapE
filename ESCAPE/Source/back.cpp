#include "back.h"
#include "backpack.h"
#include "front.h"
extern backpack item[5];
extern int backpack_count ;
extern int choosed ;
BACK_VIEW::BACK_VIEW()
{
	TOTAL_BUTTONS=10;
	BUTTON_DIM[0][0]=70 ,BUTTON_DIM[0][1]=150;
	BUTTON_DIM[1][0]=190,BUTTON_DIM[1][1]=380;
	BUTTON_DIM[2][0]=400,BUTTON_DIM[2][1]=430;
	BUTTON_DIM[3][0]=70 ,BUTTON_DIM[3][1]=150;
	BUTTON_DIM[4][0]=110,BUTTON_DIM[4][1]=110;
	BUTTON_DIM[5][0]=110,BUTTON_DIM[5][1]=110;
	BUTTON_DIM[6][0]=110,BUTTON_DIM[6][1]=110;
	BUTTON_DIM[7][0]=110,BUTTON_DIM[7][1]=110;
	BUTTON_DIM[8][0]=110,BUTTON_DIM[8][1]=110;
	BUTTON_DIM[9][0]=131,BUTTON_DIM[9][1]=110;
	BUTTON_DIM[10][0]=70,BUTTON_DIM[10][1]=70;
	BUTTON_POS[0][0]=0   ,BUTTON_POS[0][1]=300;
	BUTTON_POS[1][0]=190 ,BUTTON_POS[1][1]=240;
	BUTTON_POS[2][0]=730 ,BUTTON_POS[2][1]=240;
	BUTTON_POS[3][0]=1240,BUTTON_POS[3][1]=300;
	BUTTON_POS[4][0]=310 ,BUTTON_POS[4][1]=680;
	BUTTON_POS[5][0]=455 ,BUTTON_POS[5][1]=680;
	BUTTON_POS[6][0]=600 ,BUTTON_POS[6][1]=680;
	BUTTON_POS[7][0]=745 ,BUTTON_POS[7][1]=680;
	BUTTON_POS[8][0]=890 ,BUTTON_POS[8][1]=680;
	BUTTON_POS[9][0]=799 ,BUTTON_POS[9][1]=130;
}

bool BACK_VIEW::loadMedia() {

	bool success = true;
	if(!PNG[0].loadFromFile("back_front_picture/background_back.png")) {  // you will need to modify the path in your derived classes
		printf("Failed to load Pictures background_back.png!\n");
		success = false;
	}
	else if(!PNG[9].loadFromFile("back_front_picture/bottle_for_closet.png")) {
    printf("Failed to load Pictures bottle_for_closet.png!\n");
		success = false;
	}
	return success;
}
void BACK_VIEW::render(void) {
	PNG[0].render(0,0);
	if(TAKEBOTTLE==false)  PNG[9].render(BUTTON_POS[9][0], BUTTON_POS[9][1]);
}
int BACK_VIEW::handleEvent(SDL_Event *e, int current) {
	if(e->type == SDL_MOUSEBUTTONDOWN) {
		int x, y;
		SDL_GetMouseState( &x, &y );
		if( x > BUTTON_POS[0][0] && x < (BUTTON_POS[0][0] + BUTTON_DIM[0][0]) && y > BUTTON_POS[0][1] &&
		    y < (BUTTON_POS[0][1] + BUTTON_DIM[0][1])) {
			return 1;
		}
		else if( x > BUTTON_POS[1][0] && x < (BUTTON_POS[1][0] + BUTTON_DIM[1][0]) && y > BUTTON_POS[1][1] &&
		    y < (BUTTON_POS[1][1] + BUTTON_DIM[1][1])) {
			return 6;//doorlock
		}
		else if( x > BUTTON_POS[2][0] && x < (BUTTON_POS[2][0] + BUTTON_DIM[2][0]) && y > BUTTON_POS[2][1] &&
		    y < (BUTTON_POS[2][1] + BUTTON_DIM[2][1])) {
			return 4;//closet
		}
		else if( x > BUTTON_POS[3][0] && x < (BUTTON_POS[3][0] + BUTTON_DIM[3][0]) && y > BUTTON_POS[3][1] &&
		    y < (BUTTON_POS[3][1] + BUTTON_DIM[3][1])) {
			return 3;//left
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
			return 32;//backpack3
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
		    y < (BUTTON_POS[9][1] + BUTTON_DIM[9][1]  )&& !TAKEBOTTLE) {
            ///////
            item[0].pic.loadFromFile("backpack/bottle_backpack.png");
            item[0].setname("bottle");
            ///////
			TAKEBOTTLE=true;
			return current;
		}
		else
			return current;
	}
	return current;
}
CLOSET::CLOSET()
{
	TOTAL_BUTTONS=3;
	BUTTON_DIM[0][0]=100 ,BUTTON_DIM[0][1]=100;
	BUTTON_DIM[1][0]=130 ,BUTTON_DIM[1][1]=93;
	BUTTON_DIM[2][0]=130 ,BUTTON_DIM[2][1]=130;
	BUTTON_POS[0][0]=0   ,BUTTON_POS[0][1]=0;
	BUTTON_POS[1][0]=805  ,BUTTON_POS[1][1]=510;
	BUTTON_POS[2][0]=323  ,BUTTON_POS[2][1]=490;
}
bool CLOSET::loadMedia() {
	bool success = true;
	if(!PNG[2].loadFromFile("back_front_picture/closet.png")) {  // you will need to modify the path in your derived classes
		printf("Failed to load Pictures closet.png!\n");
		success = false;
	}
	else if(!PNG[1].loadFromFile("back_front_picture/rope.png")) {
    printf("Failed to load Pictures rope.png!\n");
		success = false;
	}
	else if(!PNG[0].loadFromFile("back_front_picture/back.png")) {
    printf("Failed to load Pictures back.png!\n");
		success = false;
	}
	else if(!PNG[3].loadFromFile("back_front_picture/Draw.png")) {
    printf("Failed to load Pictures Draw.png!\n");
		success = false;
	}
	else if(!PNG[4].loadFromFile("back_front_picture/AD.png")) {
    printf("Failed to load Pictures DRAWER_for_closet.png!\n");
		success = false;
	}
	return success;
}
void CLOSET::render(void) {
	PNG[2].render(0,0);
	PNG[0].render(BUTTON_POS[0][0], BUTTON_POS[0][1]);
	if(TAKEROPE==false) PNG[1].render(BUTTON_POS[1][0], BUTTON_POS[1][1]);
	if(TAKEDRAW==false) PNG[3].render(BUTTON_POS[2][0], BUTTON_POS[2][1]);
	else PNG[4].render(370,170);
}
int CLOSET::handleEvent(SDL_Event *e, int current) {
	if(e->type == SDL_MOUSEBUTTONDOWN) {
		int x, y;
		SDL_GetMouseState( &x, &y );
		if( x > BUTTON_POS[0][0] && x < (BUTTON_POS[0][0] + BUTTON_DIM[0][0]) && y > BUTTON_POS[0][1] &&
		    y < (BUTTON_POS[0][1] + BUTTON_DIM[0][1])) {
			return 2;
		}
		else if( x > BUTTON_POS[1][0] && x < (BUTTON_POS[1][0] + BUTTON_DIM[1][0]) && y > BUTTON_POS[1][1] &&
		    y < (BUTTON_POS[1][1] + BUTTON_DIM[1][1])) {
            item[1].pic.loadFromFile("backpack/rope_backpack.png");
            item[1].setname("rope");
            backpack_count++;
			TAKEROPE=true;
			return current;//takerope;
		}
		else if( x > BUTTON_POS[2][0] && x < (BUTTON_POS[2][0] + BUTTON_DIM[2][0]) && y > BUTTON_POS[2][1] &&
		    y < (BUTTON_POS[2][1] + BUTTON_DIM[2][1])) {
			TAKEDRAW=true;
			return current;//takerope;
        }

		else
			return current;
	}
	return current;
}
DOORLOCK::DOORLOCK()
{
	TOTAL_BUTTONS=1;
	BUTTON_DIM[0][0]=100 ,BUTTON_DIM[0][1]=100;
	BUTTON_POS[0][0]=0   ,BUTTON_POS[0][1]=0;
}
bool DOORLOCK::loadMedia() {
	bool success = true;
	if(!PNG[1].loadFromFile("back_front_picture/doorlock.png")) {  // you will need to modify the path in your derived classes
		printf("Failed to load Pictures closet.png!\n");
		success = false;
	}
	else if(!PNG[0].loadFromFile("back_front_picture/back.png")) {
    printf("Failed to load Pictures back.png!\n");
		success = false;
	}
	return success;
}
void DOORLOCK::render(void) {
	PNG[1].render(0,0);
	PNG[0].render(BUTTON_POS[0][0], BUTTON_POS[0][1]);
}
int DOORLOCK::handleEvent(SDL_Event *e, int current) {
	if(e->type == SDL_MOUSEBUTTONDOWN) {
		int x, y;
		SDL_GetMouseState( &x, &y );
		if( x > BUTTON_POS[0][0] && x < (BUTTON_POS[0][0] + BUTTON_DIM[0][0]) && y > BUTTON_POS[0][1] &&
		    y < (BUTTON_POS[0][1] + BUTTON_DIM[0][1])) {
			return 2;
		}
		else
			return current;
	}
	else if( e->type == SDL_KEYDOWN || e->type == SDL_TEXTINPUT )
	{
		//Handle backspace

		if( e->type == SDL_KEYDOWN && e->key.keysym.sym == SDLK_BACKSPACE && inputText.length() > 0 )
		{
			//lop off character
			inputText.pop_back();
		}
		else if( e->type == SDL_TEXTINPUT )
		{
			//Not copy or pasting

			if( !( ( e->text.text[ 0 ] == 'c' || e->text.text[ 0 ] == 'C' ) && ( e->text.text[ 0 ] == 'v' || e->text.text[ 0 ] == 'V' ) && SDL_GetModState() & KMOD_CTRL ) )
			{
				//Append character
				inputText += e->text.text;

			}
		}
		if(inputText=="123100002083")
        {
            end();
            return 29;
                   }
        else if(inputText.size()>=12) inputText="";
	return current;
	}
	return current;
}
