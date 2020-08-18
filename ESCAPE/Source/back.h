#ifndef back_H
#define back_H

#include <SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include "objecttemplate.h"
#include "animate.h"
using namespace std;
extern string inputText;
extern string output;
extern SDL_Renderer* gRenderer;
extern TTF_Font *gFont;
extern LTexture PNG[25];
extern bool paper;
class BACK_VIEW: public ObjectTemplate
{
  private:
	bool TAKEBOTTLE=false;

  public:
    BACK_VIEW();
    int handleEvent(SDL_Event*, int);
    bool loadMedia();
    void render();
};
class CLOSET: public ObjectTemplate
{
  private:
	bool TAKEROPE=false;
    bool TAKEDRAW=false;
  public:
    CLOSET();
    int handleEvent(SDL_Event*, int);
    bool loadMedia();
    void render();
};
class DOORLOCK: public ObjectTemplate
{
  public:
    DOORLOCK();
    int handleEvent(SDL_Event*, int);
    bool loadMedia();
    void render();
};
#endif // back_H
