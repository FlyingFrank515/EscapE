#include "objecttemplate.h"
int ObjectTemplate::handleEvent(SDL_Event *e, int current) {
	for (int i = 0; i < TOTAL_BUTTONS; i++) {
		if(e->type == SDL_MOUSEBUTTONDOWN) {
			int x, y;
			SDL_GetMouseState( &x, &y );
			bool inside = true;
			if( x < BUTTON_POS[i][0] || x > BUTTON_POS[i][0] + BUTTON_DIM[i][0]) inside = false;
			else if (y < BUTTON_POS[i][1] || y > BUTTON_POS[i][1] + BUTTON_DIM[i][1]) inside = false;
			if (!inside) continue;
			else  return 0;//return some_integer;
		}
	}
}
bool ObjectTemplate::loadMedia() {
	bool success = true;
	/*if( !PNG[0].loadFromFile( "background.png" ) ) {  // you will need to modify the path in your derived classes
		printf( "Failed to load Foo' texture image!\n" );
		success = false;
	}
	else;*/
	return success;
}
void ObjectTemplate::render() {
	for (int i = 0; i < TOTAL_BUTTONS; i++)
		PNG[i].render(BUTTON_POS[i][0], BUTTON_POS[i][1]);
}
