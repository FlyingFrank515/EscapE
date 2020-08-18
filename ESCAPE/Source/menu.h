#ifndef menu_H
#define menu_H

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
class MENU: public ObjectTemplate
{
  private:
  public:
    MENU();
    int handleEvent(SDL_Event*, int);
    bool loadMedia();
    void render();
};
class INSTRUCTION: public ObjectTemplate
{
  private:
  public:
    INSTRUCTION();
    int handleEvent(SDL_Event*, int);
    bool loadMedia();
    void render();
};
#endif
