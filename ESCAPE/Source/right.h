#ifndef right_H
#define right_H

#include <SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include "objecttemplate.h"
using namespace std;
extern string inputText;
extern string output;
extern SDL_Renderer* gRenderer;
extern TTF_Font *gFont;
extern LTexture PNG[25];
extern bool paper;

class RIGHT_VIEW: public ObjectTemplate
{
	friend class Computer_Surface;
    friend class Computer_Login;
  private:
  	int index;
  public:
    static bool watering;
    static bool curtain_down;
    RIGHT_VIEW();
    int handleEvent(SDL_Event*,int current);
    bool loadMedia();
    void render();
};
#endif // right_H
