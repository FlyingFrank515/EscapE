#include"backpack.h"
int backpack::item_count = 0;//constructor用來記錄index用的
extern int choosed;
backpack::backpack(): w(70), h(70){
	index = item_count;
	item_count++;
	switch(index){
		case 0:
			x = 330;  y = 699;
			break;
		case 1:
			x = 476;  y = 701;
			break;
		case 2:
			x = 620;  y = 703;
			break;
		case 3:
			x = 769;  y = 704;
			break;
		case 4:
			x = 911;  y = 704;
			break;
	}
	name = "nothing";
}

void backpack::render(){
	if(name == "nothing") goto END;
	pic.render(x, y);
	if(choosed == index)  PNG[24].render(x-10, y-10);
    END:;
}

bool backpack::loadMedia(std::string s){
	bool success = true;
	if( pic.loadFromFile( s.c_str()) ) {
		printf( "Failed to load pic.png!\n" );
		success = false;
	}
	return success;
}

void backpack::HandleEvent(){
    if(choosed == index || this->name == "paper") {
        choosed = 5;
    }
    else choosed = index;
}



Paper_Front::Paper_Front(){
    TOTAL_BUTTONS = 2;

    BUTTON_POS[0][0]=0   ,BUTTON_POS[0][1]=0;
    BUTTON_DIM[0][0]=100 ,BUTTON_DIM[0][1]=100;

	BUTTON_POS[1][0] = 0;    BUTTON_POS[1][1] = 0;
	BUTTON_DIM[1][0] = 1310;   BUTTON_DIM[1][1] = 794;
}

bool Paper_Front::loadMedia(){
    bool success = true;
	if( !PNG[0].loadFromFile( "backpack/back.png" ) ){
		printf( "Failed to load back.png!\n" );
		success = false;
	}
	else if(!PNG[1].loadFromFile( "backpack/paper.jpg" )){
        printf( "Failed to load paper.jpg!\n" );
		success = false;
	}
	return success;
}

void Paper_Front::render(){
    PNG[1].render(BUTTON_POS[1][0], BUTTON_POS[1][1]);
	PNG[0].render(BUTTON_POS[0][0], BUTTON_POS[0][1]);
}

int Paper_Front::handleEvent(SDL_Event* e, int current){
    if(e->type == SDL_MOUSEBUTTONDOWN) {
		int x, y;
		SDL_GetMouseState( &x, &y );
		if( x > BUTTON_POS[0][0] && x < (BUTTON_POS[0][0] + BUTTON_DIM[0][0]) && y > BUTTON_POS[0][1] &&
		    y < (BUTTON_POS[0][1] + BUTTON_DIM[0][1])) {
			return 0;
		}
		else
			return 31;
	}
	return 31;
}

////////////////////////////

Paper_Right::Paper_Right(){
    TOTAL_BUTTONS = 2;

    BUTTON_POS[0][0]=0   ,BUTTON_POS[0][1]=0;
    BUTTON_DIM[0][0]=100 ,BUTTON_DIM[0][1]=100;

	BUTTON_POS[1][0] = 0;    BUTTON_POS[1][1] = 0;
	BUTTON_DIM[1][0] = 1310;   BUTTON_DIM[1][1] = 794;
}

bool Paper_Right::loadMedia(){
    bool success = true;
	if( !PNG[0].loadFromFile( "backpack/back.png" ) ){
		printf( "Failed to load back.png!\n" );
		success = false;
	}
	else if(!PNG[1].loadFromFile( "backpack/paper.jpg" )){
        printf( "Failed to load paper.jpg!\n" );
		success = false;
	}
	return success;
}

void Paper_Right::render(){
    PNG[1].render(BUTTON_POS[1][0], BUTTON_POS[1][1]);
	PNG[0].render(BUTTON_POS[0][0], BUTTON_POS[0][1]);
}

int Paper_Right::handleEvent(SDL_Event* e, int current){
    if(e->type == SDL_MOUSEBUTTONDOWN) {
		int x, y;
		SDL_GetMouseState( &x, &y );
		if( x > BUTTON_POS[0][0] && x < (BUTTON_POS[0][0] + BUTTON_DIM[0][0]) && y > BUTTON_POS[0][1] &&
		    y < (BUTTON_POS[0][1] + BUTTON_DIM[0][1])) {
			return 1;
		}
		else
			return 34;
	}
	return 34;
}

///////////////////////////////////

Paper_Left::Paper_Left(){
    TOTAL_BUTTONS = 2;

    BUTTON_POS[0][0]=0   ,BUTTON_POS[0][1]=0;
    BUTTON_DIM[0][0]=100 ,BUTTON_DIM[0][1]=100;

	BUTTON_POS[1][0] = 0;    BUTTON_POS[1][1] = 0;
	BUTTON_DIM[1][0] = 1310;   BUTTON_DIM[1][1] = 794;
}

bool Paper_Left::loadMedia(){
    bool success = true;
	if( !PNG[0].loadFromFile( "backpack/back.png" ) ){
		printf( "Failed to load back.png!\n" );
		success = false;
	}
	else if(!PNG[1].loadFromFile( "backpack/paper.jpg" )){
        printf( "Failed to load paper.jpg!\n" );
		success = false;
	}
	return success;
}

void Paper_Left::render(){
    PNG[1].render(BUTTON_POS[1][0], BUTTON_POS[1][1]);
	PNG[0].render(BUTTON_POS[0][0], BUTTON_POS[0][1]);
}

int Paper_Left::handleEvent(SDL_Event* e, int current){
    if(e->type == SDL_MOUSEBUTTONDOWN) {
		int x, y;
		SDL_GetMouseState( &x, &y );
		if( x > BUTTON_POS[0][0] && x < (BUTTON_POS[0][0] + BUTTON_DIM[0][0]) && y > BUTTON_POS[0][1] &&
		    y < (BUTTON_POS[0][1] + BUTTON_DIM[0][1])) {
			return 3;
		}
		else
			return 33;
	}
	return 33;
}

//////////////////////////////////////////

Paper_Back::Paper_Back(){
    TOTAL_BUTTONS = 2;

    BUTTON_POS[0][0]=0   ,BUTTON_POS[0][1]=0;
    BUTTON_DIM[0][0]=100 ,BUTTON_DIM[0][1]=100;

	BUTTON_POS[1][0] = 0;    BUTTON_POS[1][1] = 0;
	BUTTON_DIM[1][0] = 1310;   BUTTON_DIM[1][1] = 794;
}

bool Paper_Back::loadMedia(){
    bool success = true;
	if( !PNG[0].loadFromFile( "backpack/back.png" ) ){
		printf( "Failed to load back.png!\n" );
		success = false;
	}
	else if(!PNG[1].loadFromFile( "backpack/paper.jpg" )){
        printf( "Failed to load paper.jpg!\n" );
		success = false;
	}
	return success;
}

void Paper_Back::render(){
    PNG[1].render(BUTTON_POS[1][0], BUTTON_POS[1][1]);
	PNG[0].render(BUTTON_POS[0][0], BUTTON_POS[0][1]);
}

int Paper_Back::handleEvent(SDL_Event* e, int current){
    if(e->type == SDL_MOUSEBUTTONDOWN) {
		int x, y;
		SDL_GetMouseState( &x, &y );
		if( x > BUTTON_POS[0][0] && x < (BUTTON_POS[0][0] + BUTTON_DIM[0][0]) && y > BUTTON_POS[0][1] &&
		    y < (BUTTON_POS[0][1] + BUTTON_DIM[0][1])) {
			return 2;
		}
		else
			return 32;
	}
	return 32;
}

/*
e.g 點擊櫃子上的水壺
bool BACK::static get = false;
int BACK::HandleEvent{
	if(在此位置&&!get){
		get = true;
		item[c].pic.loadFromFile("水壺.png");
		item.setname("水壺");
		c++
		return current;
	}
}

e.g 點擊背包中的水壺後點擊盆栽
int RIGHT::HandleEvent{
	if(在此位置&&item[choosed].return_name() == "水壺"){
		choosed = 5;
		return 流水的圖;
	}
}

main(){
	...
	if(e->type == MOUSEBUTTONDOWN){
		if(x > 330 && x < 400 && y > 699 && y < 769) item[0].HandleEvent();
		else if (x > 476 && x < 546 && y > 701 && y < 771) item[1].HandleEvent();
		else if (x > 620 && x < 690 && y > 703 && y < 773) item[2].HandleEvent();
		else if (x > 769 && x < 839 && y > 704 && y < 774) item[3].HandleEvent();
		else if (x > 911 && x < 981 && y > 704 && y < 774) item[4].HandleEvent();
		else{
			int temp = all[current] -> handleEvent(&e, current);
			current = temp;
		}
	}
	...
	SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
	for(int i = 0; i < 5; i++) item[i].render();
	SDL_RenderClear( gRenderer );
}
*/
