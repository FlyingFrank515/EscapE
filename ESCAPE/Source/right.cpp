#include "right.h"
#include "backpack.h"
#include "front.h"
extern backpack item[5];
extern int backpack_count ;
extern int choosed ;
RIGHT_VIEW::RIGHT_VIEW()
{
	watering = false;
	index = 1;
	TOTAL_BUTTONS = 4;
	BUTTON_POS[0][0] = 1240; BUTTON_POS[0][1] = 300;
  BUTTON_DIM[0][0] = 70; BUTTON_DIM[0][1] = 150;
  BUTTON_POS[1][0] = 0; BUTTON_POS[1][1] = 300;
  BUTTON_DIM[1][0] = 70; BUTTON_DIM[1][1] = 150;
  BUTTON_POS[2][0] = 920; BUTTON_POS[2][1] = 270; //pot plant 1160 380
  BUTTON_DIM[2][0] = 240; BUTTON_DIM[2][1] = 110;
  BUTTON_POS[3][0] = 400; BUTTON_POS[3][1] = 160; //curtain
  BUTTON_DIM[3][0] = 490; BUTTON_DIM[3][1] = 70;
  BUTTON_POS[4][0] = 620; BUTTON_POS[4][1] = 703;
  BUTTON_DIM[4][0] = 70; BUTTON_DIM[4][1] = 70;

}
bool RIGHT_VIEW::loadMedia() {
	bool success = true;
	if((curtain_down)? !PNG[4].loadFromFile("Pictures/view2/background_right1.png") : !PNG[4].loadFromFile("Pictures/view2/background_right.png")) {  // you will need to modify the path in your derived classes
		printf("Failed to load Pictures/view2/left_view.png!\n");
		success = false;
	}
	else if(!PNG[2].loadFromFile("Pictures/view2/atep.png")) {  // you will need to modify the path in your derived classes
		printf("Failed to load Pictures/view2/atep.png!\n");
		success = false;
	}
	else if(!PNG[5].loadFromFile("Pictures/view2/water.png")) {  // you will need to modify the path in your derived classes
		printf("Failed to load Pictures/view2/water.png!\n");
		success = false;
	}

	return success;
}

int RIGHT_VIEW::handleEvent(SDL_Event *e,int current) {
	if(e->type == SDL_MOUSEBUTTONDOWN) {
		int x, y;
		SDL_GetMouseState( &x, &y ); // right
		if( x > BUTTON_POS[0][0] && x < (BUTTON_POS[0][0] + BUTTON_DIM[0][0]) && y > BUTTON_POS[0][1] &&
		    y < (BUTTON_POS[0][1] + BUTTON_DIM[0][1])) {
			return 2;
		}
		else if( x > BUTTON_POS[1][0] && x < (BUTTON_POS[1][0] + BUTTON_DIM[1][0]) && y > BUTTON_POS[1][1] &&
		    y < (BUTTON_POS[1][1] + BUTTON_DIM[1][1])) {
			return 0;
		}
		else if (( x > BUTTON_POS[2][0] && x < (BUTTON_POS[2][0] + BUTTON_DIM[2][0]) && y > BUTTON_POS[2][1] &&
		    y < (BUTTON_POS[2][1] + BUTTON_DIM[2][1])) && item[choosed].return_name() == "bottle") {
			choosed = 5;
            watering = 1;
            this -> render();
            return index;
		}
		else if (( x > BUTTON_POS[3][0] && x < (BUTTON_POS[3][0] + BUTTON_DIM[3][0]) && y > BUTTON_POS[3][1] &&
		    y < (BUTTON_POS[3][1] + BUTTON_DIM[3][1])) && item[choosed].return_name() == "rope") {
            item[1].pic.free();
            item[1].setname("nothing");
			choosed = 5;
            curtain_down = 1;
            this -> render();
		    return index;
		}
		else if (( x > BUTTON_POS[4][0] && x < (BUTTON_POS[4][0] + BUTTON_DIM[4][0]) && y > BUTTON_POS[4][1] &&
		    y < (BUTTON_POS[4][1] + BUTTON_DIM[4][1]))&&DRAWER2::paper) {
			choosed = 5;
			return 34;
		}
		else
			return current;
	}
	return current;
}

void RIGHT_VIEW::render() {
	PNG[4].render(0, 0);
	if (watering){
        PNG[5].render(920, 285);
		PNG[2].render(BUTTON_POS[2][0], BUTTON_POS[2][1]);
	}
}
