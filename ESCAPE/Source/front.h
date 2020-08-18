#ifndef front_H
#define front_H

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
class FRONT_VIEW: public ObjectTemplate
{
  private:
  public:
    FRONT_VIEW();
    int handleEvent(SDL_Event*, int);
    bool loadMedia();
    void render();
    static bool death;
};
class DRAWER1: public ObjectTemplate
{
  private:
  public:
    DRAWER1();
    int handleEvent(SDL_Event*, int);
    bool loadMedia();
    void render();
};
class DRAWER2: public ObjectTemplate
{

  public:
    DRAWER2();
    int handleEvent(SDL_Event*, int);
    bool loadMedia();
    void render();
    static bool paper;
};
class DRAWER3: public ObjectTemplate
{
  private:
  public:
    DRAWER3();
    int handleEvent(SDL_Event*, int);
    bool loadMedia();
    void render();
};
#endif // right_H
