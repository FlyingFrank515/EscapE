#include "computer.h"
#include "right.h"
extern const int SCREEN_WIDTH ;
extern const int SCREEN_HEIGHT ;
const int SCREEN_WIDTH = 1310;
const int SCREEN_HEIGHT = 794;
Computer_Login::Computer_Login(){
	TOTAL_BUTTONS = 2;
	BUTTON_POS[0][0] = 10;    BUTTON_POS[0][1] = SCREEN_HEIGHT - 74;// power
	BUTTON_DIM[0][0] = 64;    BUTTON_DIM[0][1] = 64;

	BUTTON_POS[1][0] = 0;        BUTTON_POS[1][1] = 0;// Computer_Login
	BUTTON_DIM[1][0] = 1310;     BUTTON_DIM[1][1] = 794;
}

int Computer_Login::handleEvent(SDL_Event* e, int current){
	if(e->type == SDL_MOUSEBUTTONDOWN){
		for (int i = 0; i < TOTAL_BUTTONS; i++) {
			int x, y;
			SDL_GetMouseState( &x, &y );
			bool inside = true;
			if( x < BUTTON_POS[i][0] || x > BUTTON_POS[i][0] + BUTTON_DIM[i][0]) inside = false;
			else if (y < BUTTON_POS[i][1] || y > BUTTON_POS[i][1] + BUTTON_DIM[i][1]) inside = false;
			if (!inside) continue;
			else{
				switch(i){
					case 0:
						return 0;//front
					default:
						return current;
				}
			}
		}
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
		if(inputText=="ESIO0123")
        {
        	Computer_Login::login = true;
            return 12;//Surface
                   }
        else if(inputText.size()>=8) inputText="";
	return current;
	}
}
bool Computer_Login::loadMedia(){
	bool success = true;
	if( !PNG[1].loadFromFile( "Computer/Computer_Login.png" ) ) {
		printf( "Failed to load Computer_Login.png!\n" );
		success = false;
	}
	else if(!PNG[0].loadFromFile( "Computer/power.png" )){
		printf( "Failed to load back.png!\n" );
		success = false;
	}
	return success;
}

void Computer_Login::render(){
	PNG[1].render(BUTTON_POS[1][0], BUTTON_POS[1][1]);
	PNG[0].render(BUTTON_POS[0][0], BUTTON_POS[0][1]);
}

////////////////////////////////////////////////////////////////////////////////////////////////////

Computer_Surface::Computer_Surface(){
	TOTAL_BUTTONS = 5;

	BUTTON_POS[0][0] = 10;    BUTTON_POS[0][1] = SCREEN_HEIGHT - 74;// power
	BUTTON_DIM[0][0] = 64;    BUTTON_DIM[0][1] = 64;

	BUTTON_POS[1][0] = 40;    BUTTON_POS[1][1] = 50;// Calendar_Icon
	BUTTON_DIM[1][0] = 135;   BUTTON_DIM[1][1] = 145;

	BUTTON_POS[2][0] = 27;    BUTTON_POS[2][1] = 431;// Special_Day_Icon
	BUTTON_DIM[2][0] = 180;   BUTTON_DIM[2][1] = 225;

	BUTTON_POS[3][0] = 40;    BUTTON_POS[3][1] = 245;// Secret_Code_Icon
	BUTTON_DIM[3][0] = 170;   BUTTON_DIM[3][1] = 160;

	BUTTON_POS[4][0] = 0;     BUTTON_POS[4][1] = 0;// Computer_Surface
	BUTTON_DIM[4][0] = 1310;  BUTTON_DIM[4][1] = 794;


}

int Computer_Surface::handleEvent(SDL_Event* e, int current){
	for (int i = 0; i < TOTAL_BUTTONS ; i++) {
		if(e->type == SDL_MOUSEBUTTONDOWN) {
			int x, y;
			SDL_GetMouseState( &x, &y );
			bool inside = true;
			if( x < BUTTON_POS[i][0] || x > BUTTON_POS[i][0] + BUTTON_DIM[i][0]) inside = false;
			else if (y < BUTTON_POS[i][1] || y > BUTTON_POS[i][1] + BUTTON_DIM[i][1]) inside = false;
			if (!inside) continue;
			else{
				switch(i){
					case 0:
						return 0;//front
					case 1:
						return 13;//Calendar
					case 2:
						if(RIGHT_VIEW::watering)
							if(Special_Day::specialday)	return 24;//PassWord2;
							else return 23;//Special_Day;
						else return current;
					case 3:
						if(RIGHT_VIEW::watering){
							if(Secret_Code::secretcode)	return 28;//PassWord3_S;
						else return 26;//Secret_Code_S;
						}
						else{
							if(Secret_Code::secretcode)	return 27;//PassWord3;
						else return 25;//Secret_Code;
						}

					default:
						return current;
				}
			}
		}
	}
	return current;
}
bool Computer_Surface::loadMedia(){
	bool success = true;
	if( !PNG[0].loadFromFile( "Computer/power.png" ) ){
		printf( "power.png!\n" );
		success = false;
	}
	else if( !PNG[2].loadFromFile( "Computer/Special_Day_Icon.png" )) {
		printf( "Failed to load Special_Day_Icon.png!\n" );
		success = false;
	}
	else if( !PNG[4].loadFromFile( "Computer/Computer_Surface.png" ) ) {
		printf( "Failed to load Computer_Surface.jpg!\n" );
		success = false;
	}


	return success;
}

void Computer_Surface::render()
{
	PNG[4].render(BUTTON_POS[4][0], BUTTON_POS[4][1]);
	PNG[0].render(BUTTON_POS[0][0], BUTTON_POS[0][1]);
	if (RIGHT_VIEW::watering) PNG[2].render(BUTTON_POS[2][0], BUTTON_POS[2][1]);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Secret_Code::Secret_Code(){
	TOTAL_BUTTONS = 3;
    secretcode = false;
	BUTTON_POS[0][0] = 943;    BUTTON_POS[0][1] = 182;// Quit
	BUTTON_DIM[0][0] = 32;     BUTTON_DIM[0][1] = 34;

	BUTTON_POS[1][0] = 10;    BUTTON_POS[1][1] = SCREEN_HEIGHT - 74;// power
	BUTTON_DIM[1][0] = 64;    BUTTON_DIM[1][1] = 64;

	BUTTON_POS[2][0] = 0;      BUTTON_POS[2][1] = 0;// Secret_Code
	BUTTON_DIM[2][0] = 1310;   BUTTON_DIM[2][1] = 794;
}

int Secret_Code::handleEvent(SDL_Event* e, int current){
	if(e->type == SDL_MOUSEBUTTONDOWN) {
		for (int i = 0; i < TOTAL_BUTTONS ; i++) {
			int x, y;
			SDL_GetMouseState( &x, &y );
			bool inside = true;
			if( x < BUTTON_POS[i][0] || x > BUTTON_POS[i][0] + BUTTON_DIM[i][0]) inside = false;
			else if (y < BUTTON_POS[i][1] || y > BUTTON_POS[i][1] + BUTTON_DIM[i][1]) inside = false;
			if (!inside) continue;
			else{
				switch(i){
					case 0:
						return 12;//Computer_Surface;
					case 1:
						return 0;//Front_View;
					default:
						return current;
				}
			}
		}
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
		if(inputText=="CPPISGOOD")
        {
        	secretcode = true;
            return 27;//nextindex
                   }
        else if(inputText.size()>=9) inputText="";
	return current;
	}
	return current;
}
bool Secret_Code::loadMedia(){
	bool success = true;
	if( !PNG[1].loadFromFile( "Computer/power.png" ) ) {
		printf( "Failed to load power.png!\n" );
		success = false;
	}
	else if( !PNG[2].loadFromFile( "Computer/Secret_Code.png" ) ) {
		printf( "Failed to load Secret_Code.png!\n" );
		success = false;
	}
	return success;
}

void Secret_Code::render(){
	PNG[2].render(BUTTON_POS[2][0], BUTTON_POS[2][1]);
	PNG[1].render(BUTTON_POS[1][0], BUTTON_POS[1][1]);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Secret_Code_S::Secret_Code_S(){
	TOTAL_BUTTONS = 3;

	BUTTON_POS[0][0] = 943;    BUTTON_POS[0][1] = 182;// Quit
	BUTTON_DIM[0][0] = 32;     BUTTON_DIM[0][1] = 34;

	BUTTON_POS[1][0] = 10;    BUTTON_POS[1][1] = SCREEN_HEIGHT - 74;// power
	BUTTON_DIM[1][0] = 64;    BUTTON_DIM[1][1] = 64;

	BUTTON_POS[2][0] = 0;      BUTTON_POS[2][1] = 0;// Secret_Code_S
	BUTTON_DIM[2][0] = 1310;   BUTTON_DIM[2][1] = 794;

}

int Secret_Code_S::handleEvent(SDL_Event* e, int current){
	if(e->type == SDL_MOUSEBUTTONDOWN) {
		for (int i = 0; i < TOTAL_BUTTONS ; i++) {
			int x, y;
			SDL_GetMouseState( &x, &y );
			bool inside = true;
			if( x < BUTTON_POS[i][0] || x > BUTTON_POS[i][0] + BUTTON_DIM[i][0]) inside = false;
			else if (y < BUTTON_POS[i][1] || y > BUTTON_POS[i][1] + BUTTON_DIM[i][1]) inside = false;
			if (!inside) continue;
			else{
				switch(i){
					case 0:
						return 12;//Computer_Surface;
					case 1:
						return 0;//Front_View;
					default:
						return current;
				}
			}
		}
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
		if(inputText=="CPPISGOOD")
        {
        	Secret_Code::secretcode = true;
            return 28;//nextindex
                   }
        else if(inputText.size()>=9) inputText="";
	return current;
	}
    return current;
}
bool Secret_Code_S::loadMedia(){
	bool success = true;
	if( !PNG[1].loadFromFile( "Computer/power.png" ) ) {
		printf( "Failed to load power.png!\n" );
		success = false;
	}
	else if( !PNG[2].loadFromFile( "Computer/Secret_Code_S.png" ) ) {
		printf( "Failed to load Secret_Code_S.png!\n" );
		success = false;
	}
	return success;
}

void Secret_Code_S::render(){
	PNG[2].render(BUTTON_POS[2][0], BUTTON_POS[2][1]);
	PNG[1].render(BUTTON_POS[1][0], BUTTON_POS[1][1]);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

PassWord3::PassWord3(){
	TOTAL_BUTTONS = 3;

	BUTTON_POS[0][0] = 943;    BUTTON_POS[0][1] = 182;// Quit
	BUTTON_DIM[0][0] = 32;     BUTTON_DIM[0][1] = 34;

	BUTTON_POS[1][0] = 10;    BUTTON_POS[1][1] = SCREEN_HEIGHT - 74;// power
	BUTTON_DIM[1][0] = 64;    BUTTON_DIM[1][1] = 64;

	BUTTON_POS[2][0] = 0;      BUTTON_POS[2][1] = 0;// PassWord3
	BUTTON_DIM[2][0] = 1310;   BUTTON_DIM[2][1] = 794;

}

int PassWord3::handleEvent(SDL_Event* e, int current){
	for (int i = 0; i < TOTAL_BUTTONS ; i++) {
		if(e->type == SDL_MOUSEBUTTONDOWN) {
			int x, y;
			SDL_GetMouseState( &x, &y );
			bool inside = true;
			if( x < BUTTON_POS[i][0] || x > BUTTON_POS[i][0] + BUTTON_DIM[i][0]) inside = false;
			else if (y < BUTTON_POS[i][1] || y > BUTTON_POS[i][1] + BUTTON_DIM[i][1]) inside = false;
			if (!inside) continue;
			else{
				switch(i){
					case 0:
						return 12;//Computer_Surface;
					case 1:
						return 0;//Front_View;
					default:
						return current;
				}


			}
		}
	}
	return current;
}
bool PassWord3::loadMedia(){
	bool success = true;
	if( !PNG[1].loadFromFile( "Computer/power.png" ) ) {
		printf( "Failed to load power.png!\n" );
		success = false;
	}
	else if( !PNG[2].loadFromFile( "Computer/PassWord3.png" ) ) {
		printf( "Failed to load PassWord3.png!\n" );
		success = false;
	}
	return success;
}

void PassWord3::render(){
	PNG[2].render(BUTTON_POS[2][0], BUTTON_POS[2][1]);
	PNG[1].render(BUTTON_POS[1][0], BUTTON_POS[1][1]);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

PassWord3_S::PassWord3_S(){
	TOTAL_BUTTONS = 3;

	BUTTON_POS[0][0] = 943;    BUTTON_POS[0][1] = 182;// Quit
	BUTTON_DIM[0][0] = 32;     BUTTON_DIM[0][1] = 34;

	BUTTON_POS[1][0] = 10;    BUTTON_POS[1][1] = SCREEN_HEIGHT - 74;// power
	BUTTON_DIM[1][0] = 64;    BUTTON_DIM[1][1] = 64;

	BUTTON_POS[2][0] = 0;      BUTTON_POS[2][1] = 0;// PassWord3_S
	BUTTON_DIM[2][0] = 1310;   BUTTON_DIM[2][1] = 794;

}

int PassWord3_S::handleEvent(SDL_Event* e, int current){
	for (int i = 0; i < TOTAL_BUTTONS ; i++) {
		if(e->type == SDL_MOUSEBUTTONDOWN) {
			int x, y;
			SDL_GetMouseState( &x, &y );
			bool inside = true;
			if( x < BUTTON_POS[i][0] || x > BUTTON_POS[i][0] + BUTTON_DIM[i][0]) inside = false;
			else if (y < BUTTON_POS[i][1] || y > BUTTON_POS[i][1] + BUTTON_DIM[i][1]) inside = false;
			if (!inside) continue;
			else{
				switch(i){
					case 0:
						return 12;//Computer_Surface;
					case 1:
						return 0;//Front_View;
					default:
						return current;
				}
			}
		}
	}
	return current;
}
bool PassWord3_S::loadMedia(){
	bool success = true;
	if( !PNG[1].loadFromFile( "Computer/power.png" ) ) {
		printf( "Failed to load power.png!\n" );
		success = false;
	}
	else if( !PNG[2].loadFromFile( "Computer/PassWord3_S.png" ) ) {
		printf( "Failed to load PassWord3_S.png!\n" );
		success = false;
	}
	return success;
}

void PassWord3_S::render(){
	PNG[2].render(BUTTON_POS[2][0], BUTTON_POS[2][1]);
	PNG[1].render(BUTTON_POS[1][0], BUTTON_POS[1][1]);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Special_Day::Special_Day(){
	TOTAL_BUTTONS = 3;
    specialday = false;
	BUTTON_POS[0][0] = 943;   BUTTON_POS[0][1] = 182;// Quit
	BUTTON_DIM[0][0] = 32;    BUTTON_DIM[0][1] = 34;

	BUTTON_POS[1][0] = 10;    BUTTON_POS[1][1] = SCREEN_HEIGHT - 74;// power
	BUTTON_DIM[1][0] = 64;    BUTTON_DIM[1][1] = 64;

	BUTTON_POS[2][0] = 0;     BUTTON_POS[2][1] = 0;// Special_Day
	BUTTON_DIM[2][0] = 1310;  BUTTON_DIM[2][1] = 794;
}

int Special_Day::handleEvent(SDL_Event* e, int current){
	if(e->type == SDL_MOUSEBUTTONDOWN) {
		for (int i = 0; i < TOTAL_BUTTONS ; i++) {
			int x, y;
			SDL_GetMouseState( &x, &y );
			bool inside = true;
			if( x < BUTTON_POS[i][0] || x > BUTTON_POS[i][0] + BUTTON_DIM[i][0]) inside = false;
			else if (y < BUTTON_POS[i][1] || y > BUTTON_POS[i][1] + BUTTON_DIM[i][1]) inside = false;
			if (!inside) continue;
			else {
				switch(i)
				{
					case 0:
						return 12;
						break;//Computer_Surface;
					case 1:
						return 0;
						break;//Front_View;
					default:
						return current;
				}
			}
		}
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
		if(inputText=="20181225")
        {
        	specialday = true;
            return 24;//nextindex
                   }
        else if(inputText.size()>=8) inputText="";
	return current;
	}
	return current;
}
bool Special_Day::loadMedia(){
	bool success = true;
	if( !PNG[1].loadFromFile( "Computer/power.png" ) ) {
		printf( "Failed to load power.png!\n" );
		success = false;
	}
	else if( !PNG[2].loadFromFile( "Computer/Special_Day.png" ) ) {
		printf( "Failed to load Special_Day.png!\n" );
		success = false;
	}
	return success;
}

void Special_Day::render(){
	PNG[2].render(BUTTON_POS[2][0], BUTTON_POS[2][1]);
	PNG[1].render(BUTTON_POS[1][0], BUTTON_POS[1][1]);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////

PassWord2::PassWord2(){
	TOTAL_BUTTONS = 3;

	BUTTON_POS[0][0] = 943;    BUTTON_POS[0][1] = 182;// Quit
	BUTTON_DIM[0][0] = 32;     BUTTON_DIM[0][1] = 34;

	BUTTON_POS[1][0] = 10;     BUTTON_POS[1][1] = SCREEN_HEIGHT - 74;// power
	BUTTON_DIM[1][0] = 64;     BUTTON_DIM[1][1] = 64;

	BUTTON_POS[2][0] = 0;      BUTTON_POS[2][1] = 0;// PassWord2
	BUTTON_DIM[2][0] = 1310;   BUTTON_DIM[2][1] = 794;

}

int PassWord2::handleEvent(SDL_Event* e, int current){
	for (int i = 0; i < TOTAL_BUTTONS ; i++) {
		if(e->type == SDL_MOUSEBUTTONDOWN) {
			int x, y;
			SDL_GetMouseState( &x, &y );
			bool inside = true;
			if( x < BUTTON_POS[i][0] || x > BUTTON_POS[i][0] + BUTTON_DIM[i][0]) inside = false;
			else if (y < BUTTON_POS[i][1] || y > BUTTON_POS[i][1] + BUTTON_DIM[i][1]) inside = false;
			if (!inside) continue;
			else {
				switch(i){
					case 0:
						return 12;//Computer_Surface;
					case 1:
						return 0;//Front_View;
					default:
						return current;
				}
			}
		}
	}
	return current;
}
bool PassWord2::loadMedia(){
	bool success = true;
	if( !PNG[1].loadFromFile( "Computer/power.png" ) ) {
		printf( "Failed to load power.png!\n" );
		success = false;
	}
	else if( !PNG[2].loadFromFile( "Computer/PassWord2.png" ) ) {
		printf( "Failed to load PassWord2.png!\n" );
		success = false;
	}
	return success;
}

void PassWord2::render(){
	PNG[2].render(BUTTON_POS[2][0], BUTTON_POS[2][1]);
	PNG[1].render(BUTTON_POS[1][0], BUTTON_POS[1][1]);

}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Calendar::Calendar(){
	TOTAL_BUTTONS = 11;

	BUTTON_POS[0][0] = 1229;   BUTTON_POS[0][1] = 9;// Quit
	BUTTON_DIM[0][0] = 64;     BUTTON_DIM[0][1] = 60;

	BUTTON_POS[1][0] = 284;    BUTTON_POS[1][1] = 414;// 12/4
	BUTTON_DIM[1][0] = 75;     BUTTON_DIM[1][1] = 55;

	BUTTON_POS[2][0] = 598;    BUTTON_POS[2][1] = 412;// 12/6
	BUTTON_DIM[2][0] = 75;     BUTTON_DIM[2][1] = 55;

	BUTTON_POS[3][0] = 124;    BUTTON_POS[3][1] = 487;// 12/10
	BUTTON_DIM[3][0] = 75;     BUTTON_DIM[3][1] = 55;

	BUTTON_POS[4][0] = 755;    BUTTON_POS[4][1] = 488;// 12/14
	BUTTON_DIM[4][0] = 75;     BUTTON_DIM[4][1] = 55;

	BUTTON_POS[5][0] = 440;    BUTTON_POS[5][1] = 562;// 12/19
	BUTTON_DIM[5][0] = 75;	   BUTTON_DIM[5][1] = 55;

	BUTTON_POS[6][0] = 599;    BUTTON_POS[6][1] = 563;// 12/20
	BUTTON_DIM[6][0] = 75;     BUTTON_DIM[6][1] = 55;

	BUTTON_POS[7][0] = 754;    BUTTON_POS[7][1] = 563;// 12/21
	BUTTON_DIM[7][0] = 75;	   BUTTON_DIM[7][1] = 55;

	BUTTON_POS[8][0] = 282;    BUTTON_POS[8][1] = 636;// 12/25
	BUTTON_DIM[8][0] = 75;     BUTTON_DIM[8][1] = 55;

	BUTTON_POS[9][0] = 123;    BUTTON_POS[9][1] = 712;// 12/31
	BUTTON_DIM[9][0] = 75;     BUTTON_DIM[9][1] = 55;

	BUTTON_POS[10][0] = 0;     BUTTON_POS[10][1] = 0;// Calendar
	BUTTON_DIM[10][0] = 1310;  BUTTON_DIM[10][1] = 794;
}

int Calendar::handleEvent(SDL_Event* e, int current){
	for (int i = 0; i < TOTAL_BUTTONS ; i++) {
		if(e->type == SDL_MOUSEBUTTONDOWN) {
			int x, y;
			SDL_GetMouseState( &x, &y );
			bool inside = true;
			if( x < BUTTON_POS[i][0] || x > BUTTON_POS[i][0] + BUTTON_DIM[i][0]) inside = false;
			else if (y < BUTTON_POS[i][1] || y > BUTTON_POS[i][1] + BUTTON_DIM[i][1]) inside = false;
			if (!inside) continue;
			else {
				switch(i){
					case 0:
						return 12;//Computer_Surface;
					case 1:
						return 14;//Calendar_12_4;
					case 2:
						return 15;//Calendar_12_6;
					case 3:
						return 16;//Calendar_12_10;
					case 4:
						return 17;//Calendar_12_14;
					case 5:
						return 18;//Calendar_12_19;
					case 6:
						return 19;//Calendar_12_20;
					case 7:
						return 20;//Calendar_12_21;
					case 8:
						return 21;//Calendar_12_25;
					case 9:
						return 22;//Calendar_12_31;
					default:
						return current;
				}
			}
		}
	}
	return current;
}
bool Calendar::loadMedia(){
	bool success = true;
	if( !PNG[10].loadFromFile( "Computer/Calendar.png" ) ) {
		printf( "Failed to load Calendar.png!\n" );
		success = false;
	}
	return success;
}

void Calendar::render(){
	PNG[10].render(BUTTON_POS[10][0], BUTTON_POS[10][1]);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Calendar_12_4::Calendar_12_4(){
	TOTAL_BUTTONS = 2;

	BUTTON_POS[0][0] = 940;    BUTTON_POS[0][1] = 213;// Quit
	BUTTON_DIM[0][0] = 35;     BUTTON_DIM[0][1] = 30;

	BUTTON_POS[1][0] = 0;      BUTTON_POS[1][1] = 0;// Calendar_12_4
	BUTTON_DIM[1][0] = 1310;   BUTTON_DIM[1][1] = 794;
}

int Calendar_12_4::handleEvent(SDL_Event* e, int current){
	for (int i = 0; i < TOTAL_BUTTONS ; i++) {
		if(e->type == SDL_MOUSEBUTTONDOWN) {
			int x, y;
			SDL_GetMouseState( &x, &y );
			bool inside = true;
			if( x < BUTTON_POS[i][0] || x > BUTTON_POS[i][0] + BUTTON_DIM[i][0]) inside = false;
			else if (y < BUTTON_POS[i][1] || y > BUTTON_POS[i][1] + BUTTON_DIM[i][1]) inside = false;
			if (!inside) continue;
			else {
				switch(i){
					case 0:
						return 13;//Calendar;
					default:
						return current;
				}
			}
		}
	}
	return current;
}
bool Calendar_12_4::loadMedia(){
	bool success = true;
	if( !PNG[1].loadFromFile( "Computer/Calendar_12_04.png" ) ) {
		printf( "Failed to load Calendar_12_04.png!\n" );
		success = false;
	}
	return success;
}

void Calendar_12_4::render(){
	PNG[1].render(BUTTON_POS[1][0], BUTTON_POS[1][1]);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Calendar_12_6::Calendar_12_6(){
	TOTAL_BUTTONS = 2;

	BUTTON_POS[0][0] = 940;    BUTTON_POS[0][1] = 213;// Quit
	BUTTON_DIM[0][0] = 35;     BUTTON_DIM[0][1] = 30;

	BUTTON_POS[1][0] = 0;      BUTTON_POS[1][1] = 0;// Calendar_12_6
	BUTTON_DIM[1][0] = 1310;   BUTTON_DIM[1][1] = 794;
}

int Calendar_12_6::handleEvent(SDL_Event* e, int current){
	for (int i = 0; i < TOTAL_BUTTONS ; i++) {
		if(e->type == SDL_MOUSEBUTTONDOWN) {
			int x, y;
			SDL_GetMouseState( &x, &y );
			bool inside = true;
			if( x < BUTTON_POS[i][0] || x > BUTTON_POS[i][0] + BUTTON_DIM[i][0]) inside = false;
			else if (y < BUTTON_POS[i][1] || y > BUTTON_POS[i][1] + BUTTON_DIM[i][1]) inside = false;
			if (!inside) continue;
			else {
				switch(i){
					case 0:
						return 13;//Calendar;
					default:
						return current;
				}
			}
		}
	}
	return current;
}
bool Calendar_12_6::loadMedia(){
	bool success = true;
	if( !PNG[1].loadFromFile( "Computer/Calendar_12_06.png" ) ) {
		printf( "Failed to load Calendar_12_06.png!\n" );
		success = false;
	}
	return success;
}

void Calendar_12_6::render(){
	PNG[1].render(BUTTON_POS[1][0], BUTTON_POS[1][1]);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Calendar_12_10::Calendar_12_10(){
	TOTAL_BUTTONS = 2;

	BUTTON_POS[0][0] = 940;    BUTTON_POS[0][1] = 213;// Quit
	BUTTON_DIM[0][0] = 35;     BUTTON_DIM[0][1] = 30;

	BUTTON_POS[1][0] = 0;      BUTTON_POS[1][1] = 0;// Calendar_12_10
	BUTTON_DIM[1][0] = 1310;   BUTTON_DIM[1][1] = 794;
}

int Calendar_12_10::handleEvent(SDL_Event* e, int current){
	for (int i = 0; i < TOTAL_BUTTONS ; i++) {
		if(e->type == SDL_MOUSEBUTTONDOWN) {
			int x, y;
			SDL_GetMouseState( &x, &y );
			bool inside = true;
			if( x < BUTTON_POS[i][0] || x > BUTTON_POS[i][0] + BUTTON_DIM[i][0]) inside = false;
			else if (y < BUTTON_POS[i][1] || y > BUTTON_POS[i][1] + BUTTON_DIM[i][1]) inside = false;
			if (!inside) continue;
			else {
				switch(i){
					case 0:
						return 13;//Calendar;
					default:
						return current;
				}
			}
		}
	}
}
bool Calendar_12_10::loadMedia(){
	bool success = true;
	if( !PNG[1].loadFromFile( "Computer/Calendar_12_10.png" ) ) {
		printf( "Failed to load Calendar_12_10.png!\n" );
		success = false;
	}
	return success;
}

void Calendar_12_10::render(){
	PNG[1].render(BUTTON_POS[1][0], BUTTON_POS[1][1]);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Calendar_12_14::Calendar_12_14(){
	TOTAL_BUTTONS = 2;

	BUTTON_POS[0][0] = 940;    BUTTON_POS[0][1] = 213;// Quit
	BUTTON_DIM[0][0] = 35;     BUTTON_DIM[0][1] = 30;

	BUTTON_POS[1][0] = 0;      BUTTON_POS[1][1] = 0;// Calendar_12_14
	BUTTON_DIM[1][0] = 1310;   BUTTON_DIM[1][1] = 794;
}

int Calendar_12_14::handleEvent(SDL_Event* e, int current){
	for (int i = 0; i < TOTAL_BUTTONS ; i++) {
		if(e->type == SDL_MOUSEBUTTONDOWN) {
			int x, y;
			SDL_GetMouseState( &x, &y );
			bool inside = true;
			if( x < BUTTON_POS[i][0] || x > BUTTON_POS[i][0] + BUTTON_DIM[i][0]) inside = false;
			else if (y < BUTTON_POS[i][1] || y > BUTTON_POS[i][1] + BUTTON_DIM[i][1]) inside = false;
			if (!inside) continue;
			else {
				switch(i){
					case 0:
						return 13;//Calendar;
					default:
						return current;
				}
			}
		}
	}
	return current;
}
bool Calendar_12_14::loadMedia(){
	bool success = true;
	if( !PNG[1].loadFromFile( "Computer/Calendar_12_14.png" ) ) {
		printf( "Failed to load Calendar_12_14.png!\n" );
		success = false;
	}
	return success;
}

void Calendar_12_14::render(){
	PNG[1].render(BUTTON_POS[1][0], BUTTON_POS[1][1]);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

Calendar_12_19::Calendar_12_19(){
	TOTAL_BUTTONS = 2;

	BUTTON_POS[0][0] = 940;    BUTTON_POS[0][1] = 213;// Quit
	BUTTON_DIM[0][0] = 35;     BUTTON_DIM[0][1] = 30;

	BUTTON_POS[1][0] = 0;      BUTTON_POS[1][1] = 0;// Calendar_12_19
	BUTTON_DIM[1][0] = 1310;   BUTTON_DIM[1][1] = 794;
}

int Calendar_12_19::handleEvent(SDL_Event* e, int current){
	for (int i = 0; i < TOTAL_BUTTONS ; i++) {
		if(e->type == SDL_MOUSEBUTTONDOWN) {
			int x, y;
			SDL_GetMouseState( &x, &y );
			bool inside = true;
			if( x < BUTTON_POS[i][0] || x > BUTTON_POS[i][0] + BUTTON_DIM[i][0]) inside = false;
			else if (y < BUTTON_POS[i][1] || y > BUTTON_POS[i][1] + BUTTON_DIM[i][1]) inside = false;
			if (!inside) continue;
			else {
				switch(i){
					case 0:
						return 13;//Calendar;
					default:
						return current;
				}
			}
		}
	}
	return current;
}
bool Calendar_12_19::loadMedia(){
	bool success = true;
	if( !PNG[1].loadFromFile( "Computer/Calendar_12_19.png" ) ) {
		printf( "Failed to load Calendar_12_19.png!\n" );
		success = false;
	}
	return success;
}

void Calendar_12_19::render(){
	PNG[1].render(BUTTON_POS[1][0], BUTTON_POS[1][1]);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

Calendar_12_20::Calendar_12_20(){
	TOTAL_BUTTONS = 2;

	BUTTON_POS[0][0] = 940;    BUTTON_POS[0][1] = 213;// Quit
	BUTTON_DIM[0][0] = 35;     BUTTON_DIM[0][1] = 30;

	BUTTON_POS[1][0] = 0;      BUTTON_POS[1][1] = 0;// Calendar_12_20
	BUTTON_DIM[1][0] = 1310;   BUTTON_DIM[1][1] = 794;
}

int Calendar_12_20::handleEvent(SDL_Event* e, int current){
	for (int i = 0; i < TOTAL_BUTTONS ; i++) {
		if(e->type == SDL_MOUSEBUTTONDOWN) {
			int x, y;
			SDL_GetMouseState( &x, &y );
			bool inside = true;
			if( x < BUTTON_POS[i][0] || x > BUTTON_POS[i][0] + BUTTON_DIM[i][0]) inside = false;
			else if (y < BUTTON_POS[i][1] || y > BUTTON_POS[i][1] + BUTTON_DIM[i][1]) inside = false;
			if (!inside) continue;
			else {
				switch(i){
					case 0:
						return 13;//Calendar;
					default:
						return current;
				}
			}
		}
	}
	return current;
}
bool Calendar_12_20::loadMedia(){
	bool success = true;
	if( !PNG[1].loadFromFile( "Computer/Calendar_12_20.png" ) ) {
		printf( "Failed to load Calendar_12_20.png!\n" );
		success = false;
	}
	return success;
}

void Calendar_12_20::render(){
	PNG[1].render(BUTTON_POS[1][0], BUTTON_POS[1][1]);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Calendar_12_21::Calendar_12_21(){
	TOTAL_BUTTONS = 2;

	BUTTON_POS[0][0] = 940;    BUTTON_POS[0][1] = 213;// Quit
	BUTTON_DIM[0][0] = 35;     BUTTON_DIM[0][1] = 30;

	BUTTON_POS[1][0] = 0;      BUTTON_POS[1][1] = 0;// Calendar_12_21
	BUTTON_DIM[1][0] = 1310;   BUTTON_DIM[1][1] = 794;
}

int Calendar_12_21::handleEvent(SDL_Event* e, int current){
	for (int i = 0; i < TOTAL_BUTTONS ; i++) {
		if(e->type == SDL_MOUSEBUTTONDOWN) {
			int x, y;
			SDL_GetMouseState( &x, &y );
			bool inside = true;
			if( x < BUTTON_POS[i][0] || x > BUTTON_POS[i][0] + BUTTON_DIM[i][0]) inside = false;
			else if (y < BUTTON_POS[i][1] || y > BUTTON_POS[i][1] + BUTTON_DIM[i][1]) inside = false;
			if (!inside) continue;
			else {
				switch(i){
					case 0:
						return 13;//Calendar;
					default:
						return current;
				}
			}
		}
	}
	return current;
}
bool Calendar_12_21::loadMedia(){
	bool success = true;
	if( !PNG[1].loadFromFile( "Computer/Calendar_12_21.png" ) ) {
		printf( "Failed to load Calendar_12_21.png!\n" );
		success = false;
	}
	return success;
}

void Calendar_12_21::render(){
	PNG[1].render(BUTTON_POS[1][0], BUTTON_POS[1][1]);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Calendar_12_25::Calendar_12_25(){
	TOTAL_BUTTONS = 2;

	BUTTON_POS[0][0] = 940;    BUTTON_POS[0][1] = 213;// Quit
	BUTTON_DIM[0][0] = 35;     BUTTON_DIM[0][1] = 30;

	BUTTON_POS[1][0] = 0;      BUTTON_POS[1][1] = 0;// Calendar_12_25
	BUTTON_DIM[1][0] = 1310;   BUTTON_DIM[1][1] = 794;
}

int Calendar_12_25::handleEvent(SDL_Event* e, int current){
	for (int i = 0; i < TOTAL_BUTTONS ; i++) {
		if(e->type == SDL_MOUSEBUTTONDOWN) {
			int x, y;
			SDL_GetMouseState( &x, &y );
			bool inside = true;
			if( x < BUTTON_POS[i][0] || x > BUTTON_POS[i][0] + BUTTON_DIM[i][0]) inside = false;
			else if (y < BUTTON_POS[i][1] || y > BUTTON_POS[i][1] + BUTTON_DIM[i][1]) inside = false;
			if (!inside) continue;
			else {
				switch(i){
					case 0:
						return 13;//Calendar;
					default:
						return current;
				}
			}
		}
	}
	return current;
}
bool Calendar_12_25::loadMedia(){
	bool success = true;
	if( !PNG[1].loadFromFile( "Computer/Calendar_12_25.png" ) ) {
		printf( "Failed to load Calendar_12_25.png!\n" );
		success = false;
	}
	return success;
}

void Calendar_12_25::render(){
	PNG[1].render(BUTTON_POS[1][0], BUTTON_POS[1][1]);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Calendar_12_31::Calendar_12_31(){
	TOTAL_BUTTONS = 2;

	BUTTON_POS[0][0] = 940;    BUTTON_POS[0][1] = 213;// Quit
	BUTTON_DIM[0][0] = 35;     BUTTON_DIM[0][1] = 30;

	BUTTON_POS[1][0] = 0;      BUTTON_POS[1][1] = 0;// Calendar_12_31
	BUTTON_DIM[1][0] = 1310;   BUTTON_DIM[1][1] = 794;
}

int Calendar_12_31::handleEvent(SDL_Event* e, int current){
	for (int i = 0; i < TOTAL_BUTTONS ; i++) {
		if(e->type == SDL_MOUSEBUTTONDOWN) {
			int x, y;
			SDL_GetMouseState( &x, &y );
			bool inside = true;
			if( x < BUTTON_POS[i][0] || x > BUTTON_POS[i][0] + BUTTON_DIM[i][0]) inside = false;
			else if (y < BUTTON_POS[i][1] || y > BUTTON_POS[i][1] + BUTTON_DIM[i][1]) inside = false;
			if (!inside) continue;
			else {
				switch(i){
					case 0:
						return 13;//Calendar;
					default:
						return current;
				}
			}
		}
	}
	return current;
}
bool Calendar_12_31::loadMedia(){
	bool success = true;
	if( !PNG[1].loadFromFile( "Computer/Calendar_12_31.png" ) ) {
		printf( "Failed to load Calendar_12_31.png!\n" );
		success = false;
	}
	return success;
}

void Calendar_12_31::render(){
	PNG[1].render(BUTTON_POS[1][0], BUTTON_POS[1][1]);
}
