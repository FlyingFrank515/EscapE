#include <ctime>
#include "animate.h"
void begin()
{
    for(int i=1;i<20;i++) PNG[i].free();
    if(!PNG[0].loadFromFile("story/story1.png")) {  // you will need to modify the path in your derived classes
            printf("Failed to load Pictures background_back.png!\n");
    }
    if(!PNG[1].loadFromFile("story/story2.png")) {  // you will need to modify the path in your derived classes
            printf("Failed to load Pictures background_back.png!\n");
    }
    for(int i=0;i<2;i++){
        for(int j=0;j<i;j++) PNG[j].free();
        SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
        SDL_RenderClear( gRenderer );
        PNG[i].render(0,0);
        SDL_RenderPresent( gRenderer );
        clock_t now = clock();
        SDL_Event x;
        while ((clock() - now)/CLOCKS_PER_SEC < 5.5) SDL_PollEvent( &x );
    }
}
void end()
{
    for(int i=0;i<20;i++) PNG[i].free();
    if(!PNG[1].loadFromFile("story/end1.png")) {  // you will need to modify the path in your derived classes
            printf("Failed to load Pictures end1.png!\n");
    }
    if(!PNG[2].loadFromFile("story/end2.png")) {  // you will need to modify the path in your derived classes
            printf("Failed to load Pictures end2.png!\n");
    }
    if(!PNG[3].loadFromFile("story/end3.png")) {  // you will need to modify the path in your derived classes
            printf("Failed to load Pictures end3.png!\n");
    }
    for(int i=1;i<4;i++){
        for(int j=1;j<i;j++) PNG[j].free();
        SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
        SDL_RenderClear( gRenderer );
        PNG[i].render(0,0);
        SDL_RenderPresent( gRenderer );
        clock_t now = clock();
        SDL_Event x;
        while ((clock() - now)/CLOCKS_PER_SEC < 4) SDL_PollEvent( &x );
    }
}
void broken()
{
    for(int i=0;i<20;i++) PNG[i].free();
    if(!PNG[1].loadFromFile("story/surprise1.png")) {  // you will need to modify the path in your derived classes
            printf("Failed to load Pictures background_back.png!\n");
    }
    if(!PNG[2].loadFromFile("story/surprise2.png")) {  // you will need to modify the path in your derived classes
            printf("Failed to load Pictures background_back.png!\n");
    }
    for(int i=1;i<3;i++){
        for(int j=1;j<i;j++) PNG[j].free();

        SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
        SDL_RenderClear( gRenderer );
        PNG[i].render(0,0);
        SDL_RenderPresent( gRenderer );
        clock_t now = clock();
        SDL_Event x;
        while ((clock() - now)/CLOCKS_PER_SEC < 3.5) SDL_PollEvent( &x );

    }
}
