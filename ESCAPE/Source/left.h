#ifndef left_H
#define left_H


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
class LEFT_VIEW: public ObjectTemplate
{
	friend class Safe;
  private:
    int index;
  public:
    LEFT_VIEW();
    static bool open;
    int handleEvent(SDL_Event*,int current);
    bool loadMedia();
    void render();
};
class Safe: public ObjectTemplate
{
  private:
    int index;
    int answer[16];
  public:
  	Safe();
    static bool pressed[16];
    int handleEvent(SDL_Event*,int current);
    bool loadMedia();
    void render();
};
#endif // left_H
