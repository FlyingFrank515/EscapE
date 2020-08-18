#include <SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include "back.h"
#include "front.h"
#include "left.h"
#include "right.h"
#include "LTexture.h"
#include "objecttemplate.h"
#include "computer.h"
#include "menu.h"
//////////////////////
#include "backpack.h"
/////////////////////
using namespace std;
const int SCREEN_WIDTH = 1310;
const int SCREEN_HEIGHT = 794;
string inputText="";
string output="";
SDL_Color textColor = { 0, 0, 0, 0xFF };
SDL_Color textColor_white = { 255,255,255,0XFF};
SDL_Window* gWindow = NULL;
SDL_Renderer* gRenderer = NULL;
TTF_Font *gFont = NULL;
LTexture gInputTextTexture;
LTexture PNG[25];
int state=0;
bool Secret_Code::secretcode = false;
bool RIGHT_VIEW::watering = false;
bool Special_Day::specialday = false;
bool Computer_Login::login = false;
bool Safe::pressed[16] = {false};
bool LEFT_VIEW::open = false;
bool RIGHT_VIEW::curtain_down = false;
bool DRAWER2::paper=false;
bool FRONT_VIEW::death=false;
//////////////////////
int backpack_count = 0;//被放到第幾個
int choosed = 5;
backpack item[5];
/////////////////////
bool init();
void close();
bool init()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
		{
			printf( "Warning: Linear texture filtering not enabled!" );
		}

		//Create window
		gWindow = SDL_CreateWindow( "EscapE!!!", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( gWindow == NULL )
		{
			printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{
			//Create renderer for window
			gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED );
			if( gRenderer == NULL )
			{
				printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if( !( IMG_Init( imgFlags ) & imgFlags ) )
				{
					printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
					success = false;
				}
				 //Initialize SDL_ttf
				if( TTF_Init() == -1 )
				{
					printf( "SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError() );
					success = false;
				}


			}
		}
	}
	return success;
}
void close()
{
	SDL_DestroyRenderer( gRenderer );
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;
	gRenderer = NULL;
	IMG_Quit();
	SDL_Quit();
}
int main( int argc, char* args[] )
{
	SDL_StartTextInput();
	if( !init() )
		printf( "Failed to initialize!\n" );
	else
	{
		int current = 29;
		////
		int X, Y;//滑鼠
		////
		gFont = TTF_OpenFont( "ASAP.otf", 50 );
		if( gFont == NULL ) printf( "Failed to load ASAP font! SDL_ttf Error: %s\n", TTF_GetError() );
		FRONT_VIEW a;  //0
		RIGHT_VIEW b;  //1
        BACK_VIEW c;   //2
        LEFT_VIEW d;   //3
        CLOSET E;      //4
        Safe f;        //5
        DOORLOCK g;    //6
        DRAWER1 h;     //7
        DRAWER2 i;     //8
        DRAWER3 j;     //9
        DRAWER3 k;     //10
        Computer_Login l;//11
        Computer_Surface m;//12
        Calendar n;    //13
        Calendar_12_4 o;//14
        Calendar_12_6 p;//15
        Calendar_12_10 q;//16
        Calendar_12_14 r;//17
        Calendar_12_19 s;//18
        Calendar_12_20 t;//19
        Calendar_12_21 u;//20
        Calendar_12_25 v;//21
        Calendar_12_31 w;//22
        Special_Day x;   //23
        PassWord2 y;     //24
        Secret_Code z;   //25
        Secret_Code_S alpha;//26
        PassWord3 beta;  //27
        PassWord3_S gamma;//28
        MENU theta;//29
        INSTRUCTION delta;//30
        Paper_Front fr;   //31
        Paper_Back ba;    //32
        Paper_Left le;    //33
        Paper_Right ri;   //34
		ObjectTemplate* all[40] = {&a,&b,&c,&d,&E,&f,&g,&h,&i,&j,&k,&l,&m,&n,&o,&p,
                                   &q,&r,&s,&t,&u,&v,&w,&x,&y,&z,&alpha,&beta,&gamma,&theta,&delta,&fr,&ba,&le,&ri};
		SDL_RenderClear( gRenderer );
		SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
		all[current] ->loadMedia();
		all[current] -> render();
		SDL_RenderPresent(gRenderer);
		////
		if (!PNG[24].loadFromFile("backpack/frame.png"))
            cout << "Failed to load frame !" << endl;
        if(!PNG[23].loadFromFile("backpack/paper.jpg"))
            cout << "Failed to load paper !" << endl;
		////
		if(!all[current] -> loadMedia()) printf( "Failed to load media!\n" );
		else
        {
            flag:
			bool quit = false;
			SDL_Event e;

			while(!quit)
			{
				output="";
				if(current==23 ||current==25||current==26||current==6||current==11)
				{
					for(int i=0;i<inputText.size();i++)	output+="*";
					if(current!=6) gInputTextTexture.loadFromRenderedText( output.c_str(), textColor );
					else gInputTextTexture.loadFromRenderedText( output.c_str(), textColor_white );
					if(current==23 ||current==25||current==26) gInputTextTexture.render(447,443);
                    else if(current==6) gInputTextTexture.render(446,241);
                    else if(current==11) gInputTextTexture.render(490,545);
                    SDL_RenderPresent( gRenderer );
    			}
				while( SDL_PollEvent( &e ) != 0 )
				{

					if( e.type == SDL_QUIT ) quit = true;
					else if (e.type == SDL_MOUSEBUTTONDOWN || e.type == SDL_KEYDOWN || e.type == SDL_TEXTINPUT )
					{
					    /////////
					    SDL_GetMouseState( &X, &Y );
					    if(e.type == SDL_MOUSEBUTTONDOWN && X > 330 && X < 400 && Y > 699 && Y < 769 ) item[0].HandleEvent();
					    else if(e.type == SDL_MOUSEBUTTONDOWN && X > 476 && X < 546 && Y > 701 && Y < 771 )item[1].HandleEvent();
					    else if(e.type == SDL_MOUSEBUTTONDOWN && X > 769 && X < 839 && Y > 704 && Y < 774 )item[3].HandleEvent();
					    else if(e.type == SDL_MOUSEBUTTONDOWN && X > 911 && X < 981 && Y > 704 && Y < 774 )item[4].HandleEvent();
					    else{
                        /////////
						int temp = all[current] -> handleEvent(&e, current);
						if(temp!=current) inputText="";
						current = temp;
						////
					    }
					    ////
					}
					else
						goto flag;
				}
				//Clear screen
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

				SDL_RenderClear( gRenderer );
				for(int i=0;i<24;i++) PNG[i].free();
				all[current] -> loadMedia();
				all[current] -> render();
				////////
				if (current == 0 || current == 1 || current == 2 || current == 3)
                for(int i = 0; i < 5; i++)  item[i].render();
				////////
				//Update screen
				SDL_RenderPresent( gRenderer );
			}
        }

	}
	close();
    system("pause");
	return 0;
}
