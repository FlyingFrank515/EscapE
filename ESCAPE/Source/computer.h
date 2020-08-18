#ifndef computer_H
#define computer_H

#include <SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include "objecttemplate.h"
#include "front.h"
using namespace std;
extern string inputText;
extern string output;
extern SDL_Renderer* gRenderer;
extern TTF_Font *gFont;
extern LTexture PNG[25];
class Computer_Login : public ObjectTemplate
{
	friend int FRONT_VIEW::handleEvent(SDL_Event* e, int current);
	public:
		static bool login;
		Computer_Login();
		int handleEvent(SDL_Event*, int);
    	bool loadMedia();
    	void render();

};
class Computer_Surface : public ObjectTemplate
{
	public:
		Computer_Surface();
		int handleEvent(SDL_Event*, int);
    	bool loadMedia();
    	void render();

};
class Secret_Code_S : public ObjectTemplate
{
	public:
		Secret_Code_S();
		int handleEvent(SDL_Event*, int);
    	bool loadMedia();
    	void render();

};
class Secret_Code : public ObjectTemplate
{
	friend int Secret_Code_S::handleEvent(SDL_Event* e, int current);
	friend int Computer_Surface::handleEvent(SDL_Event* e, int current);
	public:
		Secret_Code();
		int handleEvent(SDL_Event*, int);
    	bool loadMedia();
    	void render();
    	static bool secretcode;
};
class PassWord3 : public ObjectTemplate
{
	public:
		PassWord3();
		int handleEvent(SDL_Event*, int);
    	bool loadMedia();
    	void render();
};
class PassWord3_S : public ObjectTemplate
{
	public:
		PassWord3_S();
		int handleEvent(SDL_Event*, int);
    	bool loadMedia();
    	void render();
};
class Special_Day : public ObjectTemplate
{
	friend int Computer_Surface::handleEvent(SDL_Event* e, int current);
	static bool specialday;
	public:
		Special_Day();
		int handleEvent(SDL_Event*, int);
    	bool loadMedia();
    	void render();

};
class PassWord2 : public ObjectTemplate
{
	public:
		PassWord2();
		int handleEvent(SDL_Event*, int);
    	bool loadMedia();
    	void render();
};
class Calendar : public ObjectTemplate
{
	public:
		Calendar();
		int handleEvent(SDL_Event*, int);
    	bool loadMedia();
    	void render();
};
class Calendar_12_4 : public ObjectTemplate
{
	public:
		Calendar_12_4();
		int handleEvent(SDL_Event*, int);
    	bool loadMedia();
    	void render();
};
class Calendar_12_6 : public ObjectTemplate
{
	public:
		Calendar_12_6();
		int handleEvent(SDL_Event*, int);
    	bool loadMedia();
    	void render();
};
class Calendar_12_10 : public ObjectTemplate
{
	public:
		Calendar_12_10();
		int handleEvent(SDL_Event*, int);
    	bool loadMedia();
    	void render();
};
class Calendar_12_14 : public ObjectTemplate
{
	public:
		Calendar_12_14();
		int handleEvent(SDL_Event*, int);
    	bool loadMedia();
    	void render();
};
class Calendar_12_19 : public ObjectTemplate
{
	public:
		Calendar_12_19();
		int handleEvent(SDL_Event*, int);
    	bool loadMedia();
    	void render();
};
class Calendar_12_20 : public ObjectTemplate
{
	public:
		Calendar_12_20();
		int handleEvent(SDL_Event*, int);
    	bool loadMedia();
    	void render();
};
class Calendar_12_21 : public ObjectTemplate
{
	public:
		Calendar_12_21();
		int handleEvent(SDL_Event*, int);
    	bool loadMedia();
    	void render();
};
class Calendar_12_25 : public ObjectTemplate
{
	public:
		Calendar_12_25();
		int handleEvent(SDL_Event*, int);
    	bool loadMedia();
    	void render();
};
class Calendar_12_31 : public ObjectTemplate
{
	public:
		Calendar_12_31();
		int handleEvent(SDL_Event*, int);
    	bool loadMedia();
    	void render();
};
#endif // computer_H
