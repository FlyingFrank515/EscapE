#include <SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include "objecttemplate.h"

class backpack{
    friend class RIGHT_VIEW;
	public:
		backpack();
		void render();
		bool loadMedia(std::string);
		void HandleEvent();
		void setname(std::string s){ name = s; }
		string return_name(){ return name; }
		LTexture pic;
	private:
	    static int item_count;
		int x, y;//位置
		int index;//第幾個格子
		const int w, h;
		string name;
};
//void paper_render(SDL_Event*);

class Paper_Front: public ObjectTemplate{
    private:
    public:
    Paper_Front();
    int handleEvent(SDL_Event*, int);
    bool loadMedia();
    void render();
};
class Paper_Back: public ObjectTemplate{
    private:
    public:
    Paper_Back();
    int handleEvent(SDL_Event*, int);
    bool loadMedia();
    void render();
};
class Paper_Right: public ObjectTemplate{
    private:
    public:
    Paper_Right();
    int handleEvent(SDL_Event*, int);
    bool loadMedia();
    void render();
};
class Paper_Left: public ObjectTemplate{
    private:
    public:
    Paper_Left();
    int handleEvent(SDL_Event*, int);
    bool loadMedia();
    void render();
};

