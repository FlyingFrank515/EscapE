#ifndef objecttemplate_H
#define objecttemplate_H

#include <SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include "LTexture.h"
using namespace std;
extern string inputText;
extern string output;
extern SDL_Renderer* gRenderer;
extern TTF_Font *gFont;
extern LTexture PNG[25];
class ObjectTemplate
{
  protected:
  	int TOTAL_BUTTONS;
  	int BUTTON_DIM[25][2];
  	int BUTTON_POS[25][2];
  public:
  	ObjectTemplate() { }
  	~ObjectTemplate() { }
    virtual int handleEvent(SDL_Event*, int);
    virtual bool loadMedia();
    virtual void render();
};
#endif // objecttemplate_H
