#include "left.h"
#include "right.h"
#include "front.h"
extern int choosed ;
LEFT_VIEW::LEFT_VIEW()  // 0: right, 1: left, 2: safe_open 3:safe
{
	index = 3;
	TOTAL_BUTTONS = 3;
  BUTTON_POS[0][0] = 1240; BUTTON_POS[0][1] = 300;
  BUTTON_DIM[0][0] = 70; BUTTON_DIM[0][1] = 150;
  BUTTON_POS[1][0] = 0; BUTTON_POS[1][1] = 300;
  BUTTON_DIM[1][0] = 70; BUTTON_DIM[1][1] = 150;
  BUTTON_POS[2][0] = 917; BUTTON_POS[2][1] = 380;
  BUTTON_DIM[2][0] = 291; BUTTON_DIM[2][1] = 303;
  BUTTON_POS[3][0] = 620; BUTTON_POS[3][1] = 703;
  BUTTON_DIM[3][0] = 70; BUTTON_DIM[3][1] = 70;
}

int LEFT_VIEW::handleEvent(SDL_Event *e,int current) {
	if(e->type == SDL_MOUSEBUTTONDOWN) {
		int x, y;
		SDL_GetMouseState( &x, &y );
		if( x > BUTTON_POS[0][0] && x < (BUTTON_POS[0][0] + BUTTON_DIM[0][0]) && y > BUTTON_POS[0][1] &&
		    y < (BUTTON_POS[0][1] + BUTTON_DIM[0][1])) {
			return  0;
		}
		else if( x > BUTTON_POS[1][0] && x < (BUTTON_POS[1][0] + BUTTON_DIM[1][0]) && y > BUTTON_POS[1][1] &&
		    y < (BUTTON_POS[1][1] + BUTTON_DIM[1][1])) {
			return 2;
		}
		else if( x > BUTTON_POS[2][0] && x < (BUTTON_POS[2][0] + BUTTON_DIM[2][0]) && y > BUTTON_POS[2][1] &&
		    y < (BUTTON_POS[2][1] + BUTTON_DIM[2][1])) {
			if (open)
				return index;
			else
				return 5;
		}
		else if( x > BUTTON_POS[3][0] && x < (BUTTON_POS[3][0] + BUTTON_DIM[3][0]) && y > BUTTON_POS[3][1] &&
		    y < (BUTTON_POS[3][1] + BUTTON_DIM[3][1])&&DRAWER2::paper) {
			choosed = 5;
			return 33;

		}
		else
			return current;
	}
	return current;
}

bool LEFT_VIEW::loadMedia() {
	bool success = true;
	if(!PNG[3].loadFromFile("Pictures/view0/background_left.png")) {  // you will need to modify the path in your derived classes
		printf("Failed to load Pictures/view0/background.png!\n");
		success = false;
	}
	else if ((open)? !PNG[2].loadFromFile("Pictures/view0/1.png"): !PNG[2].loadFromFile("Pictures/view0/0.png")) {
		printf("Failed to load Pictures/view0/1.png!\n");
		success = false;
	}
	else if ((RIGHT_VIEW::curtain_down)? !PNG[4].loadFromFile("Pictures/view0/yescode.png"): !PNG[4].loadFromFile("Pictures/view0/nocode.png")) {
		printf("Failed to load Pictures/view0/code.png!\n");
		success = false;
	}
	else if (open)
        if (!PNG[5].loadFromFile("Pictures/view0/final_code.png")){
		    printf("Failed to load Pictures/view0/final_code.png!\n");
		    success = false;
	    }


	return success;
}

void LEFT_VIEW::render() {
	PNG[3].render(0, 0);
	PNG[2].render(BUTTON_POS[2][0], BUTTON_POS[2][1]);
    PNG[4].render(488, 207);
    if (open)
        PNG[5].render(BUTTON_POS[2][0] + 76, BUTTON_POS[2][1] + 116);
}


Safe::Safe() {
	TOTAL_BUTTONS = 17;
	for (int i = 0; i < 16; i++)
	  answer[i] = 0;
	answer[0] = answer[2] = answer[4] = answer[6] = answer[8] = answer[11] = answer[12] = answer[13] = answer[15] = 1;

  BUTTON_POS[0][0] = 392; BUTTON_POS[0][1] = 152;
  BUTTON_POS[1][0] = 534; BUTTON_POS[1][1] = 152;
  BUTTON_POS[2][0] = 679; BUTTON_POS[2][1] = 152;
  BUTTON_POS[3][0] = 821; BUTTON_POS[3][1] = 152;
  BUTTON_POS[4][0] = 392; BUTTON_POS[4][1] = 289;
  BUTTON_POS[5][0] = 534; BUTTON_POS[5][1] = 289;
  BUTTON_POS[6][0] = 679; BUTTON_POS[6][1] = 289;
  BUTTON_POS[7][0] = 821; BUTTON_POS[7][1] = 289;
  BUTTON_POS[8][0] = 392; BUTTON_POS[8][1] = 426;
  BUTTON_POS[9][0] = 534; BUTTON_POS[9][1] = 426;
  BUTTON_POS[10][0] = 679; BUTTON_POS[10][1] = 426;
  BUTTON_POS[11][0] = 821; BUTTON_POS[11][1] = 426;
  BUTTON_POS[12][0] = 392; BUTTON_POS[12][1] = 561;
  BUTTON_POS[13][0] = 534; BUTTON_POS[13][1] = 561;
  BUTTON_POS[14][0] = 679; BUTTON_POS[14][1] = 561;
  BUTTON_POS[15][0] = 821; BUTTON_POS[15][1] = 561;
  for (int i = 0; i < 16; i++) {
  	BUTTON_DIM[i][0] = 97;
  	BUTTON_DIM[i][1] = 91;
  }
  BUTTON_DIM[17][0] = 100; BUTTON_DIM[17][1] = 100;
  BUTTON_POS[17][0] = 0; BUTTON_POS[17][1] = 0;
  index = 5;
}

bool Safe::loadMedia() {
	bool success = true;
	for (int i = 0; i <= 17; i++) {
	  PNG[i].free();}

	if(!PNG[16].loadFromFile("Pictures/view0/code.png")) {  // you will need to modify the path in your derived classes
		printf("Failed to load Pictures/view0/code.png!\n");
		success = false;
	}
	else if (!PNG[17].loadFromFile("Pictures/view0/back.png")) {  // you will need to modify the path in your derived classes
		printf("Failed to load Pictures/view0/back.png!\n");
		success = false;
	}
	for (int i = 0; i < 16; i++) {
	  if (pressed[i])
	    success = PNG[i].loadFromFile("Pictures/view0/red.png")	;
	  else
	    success = PNG[i].loadFromFile("Pictures/view0/white.png");
    }
	return success;
}

int Safe::handleEvent(SDL_Event *e ,int current ) {
	if(e->type == SDL_MOUSEBUTTONDOWN) {
		int x, y;
		SDL_GetMouseState( &x, &y );
		for (int i = 0; i < 16; i++) {
		  if (x > BUTTON_POS[i][0] && x < (BUTTON_POS[i][0] + BUTTON_DIM[i][0]) && y > BUTTON_POS[i][1] &&
		      y < (BUTTON_POS[i][1] + BUTTON_DIM[i][1])) {
		    if (pressed[i])
			    pressed[i] = false;
		    else
			    pressed[i] = true;
		  }
		}
		if( x > BUTTON_POS[17][0] && x < (BUTTON_POS[17][0] + BUTTON_DIM[17][0]) && y > BUTTON_POS[17][1] &&
		    y < (BUTTON_POS[17][1] + BUTTON_DIM[17][1])) {
			return  3;
		}
	}
	bool judge = true;
	for (int i = 0; i < 16; i++)
		if (pressed[i] != answer[i])
      judge = false;
  if (judge) {
  	LEFT_VIEW::open = true;
  	return 3;
  }
  return current;
}
void Safe::render (void) {
	PNG[16].render(0, 0);
	for(int i = 0; i < 16; i++) {
		PNG[i].render(BUTTON_POS[i][0], BUTTON_POS[i][1]);
    }
	PNG[17].render(BUTTON_POS[17][0], BUTTON_POS[17][1]);

}
