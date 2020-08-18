#ifndef LTexture_H
#define LTexture_H

#include <SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;
extern string inputText;
extern string output;
extern SDL_Renderer* gRenderer;
extern TTF_Font *gFont;
class LTexture
{
	public:
		LTexture();
		~LTexture();
		bool loadFromFile( std::string path );
		void free();
		#ifdef _SDL_TTF_H
		bool loadFromRenderedText( std::string textureText, SDL_Color textColor );
		#endif
		void render( int x, int y );
		int getWidth();
		int getHeight();
	private:
		SDL_Texture* mTexture;
		int mWidth;
		int mHeight;
};
#endif // LTexture
