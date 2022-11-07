#include <iostream>

#include "SDL.h"
#include <SDL2/SDL_image.h>

// #include "src/nonogram.hpp"
int SCREEN_WIDTH = 640;
int SCREEN_HEIGHT = 480;

SDL_Window* gWindow = NULL;
SDL_Surface* gScreenSurface = NULL;
SDL_Surface* gHelloWorld = NULL;

SDL_Renderer* gRenderer = NULL;
SDL_Texture* gTexture = NULL;

bool init() {
    //Initialization flag
    bool success = true;

    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
        success = false;
    }
    else
    {
        //Create window
        gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        if( gWindow == NULL )
        {
            printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
            success = false;
        }
        else
        {
            // Create renderer for window
            gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED );
            if (gRenderer == NULL) {
                printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
                success = false; 
            } else {
                // Initialize renderer color
                SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

                //Initialize PNG loading
                int imgFlags = IMG_INIT_PNG;
                if ( !( IMG_Init( imgFlags ) & imgFlags ) ) {
                    printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
                    success = false;
                } else {
                    // Get window surface
                    gScreenSurface = SDL_GetWindowSurface( gWindow );
                    if ( gScreenSurface == NULL) {
                        printf( "Screen surface could not be loaded! SDL Error: %s\n", SDL_GetError() );
                        success = false;
                    }
                }
            }
        }
    }
    return success;
}

SDL_Surface* loadSurface( std::string path ) {
    // The final optimized image
    SDL_Surface* optimizedSurface = NULL;

    // Load image at specified path
    SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
    if ( loadedSurface == NULL ) {
        printf( "Unable to load image %s! SDL_Image Error: %s\n", path.c_str(), IMG_GetError() );
    } else {
        // Convert surface to screen format
        optimizedSurface = SDL_ConvertSurface( loadedSurface, gScreenSurface->format, 0 );
        if (optimizedSurface == NULL) {
            printf( "Unable to optimize image %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
        }
        // Get rid of old loaded surface
        SDL_FreeSurface( loadedSurface );
    }
    return optimizedSurface;
}

bool loadMedia() {
    // Loading success flag.
    bool success = true;

    // Load splash image
    gHelloWorld = loadSurface("HelloWorld.bmp");

    if ( gHelloWorld == NULL ) {
        printf( "Unable to load image %s! SDL Error: %s\n", "HelloWorld.bmp", SDL_GetError() );
        success = false;
    }
    return success;
}

void close() {
    // Free loaded image 
    SDL_DestroyTexture(gTexture);
    gTexture = NULL;

    // Destroy window
    SDL_DestroyRenderer( gRenderer );
    SDL_DestroyWindow( gWindow );
    gRenderer = NULL;
    gWindow = NULL;

    // Quit SDL subsystems 
    SDL_Quit();
}

void eventLoop() {
    SDL_Event e;
    bool quit = false;
    while (!quit) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                quit = true;
            }
            if (e.type == SDL_KEYDOWN) {
                quit = true;
            }
            // if (e.type == SDL_MOUSEBUTTONDOWN) {
            //     quit = true;
            // }
        }
        // SDL_SetRenderDrawColor(gRenderer)
    }
    close();
}

int main(int argc, char** argv) {
    // srand(std::time(NULL));
    // Nonogram test = Nonogram();
    // for (int i  = 0; i < test.getHeight(); ++i) {
    //     for (int j = 0; j < test.getWidth(); ++j ) {
    //         std::cout << test.getCell(i, j) << std::endl;
    //     } 
    // }
    // std::cout << "Randomized." << std::endl;
    // test.randomizeCells();
    // for (int i  = 0; i < test.getHeight(); ++i) {
    //     for (int j = 0; j < test.getWidth(); ++j ) {
    //         std::cout << test.getCell(i, j) << std::endl;
    //     } 
    // }
    if ( !init() ) {
        printf( "Failed to initialize!\n" );
    } 
    // else {
    //     // Load Media
    //     if ( !loadMedia() ) {
    //         printf( "Failed to load media!\n" );
    //     } else {
    //         SDL_Rect stretchRect;
    //         stretchRect.x = 0;
    //         stretchRect.y = 0;
    //         stretchRect.w = SCREEN_WIDTH;
    //         stretchRect.h = SCREEN_HEIGHT;
    //         // Apply the image
    //         SDL_BlitScaled( gHelloWorld, NULL, gScreenSurface, &stretchRect );

    //         // Update the surface
    //         SDL_UpdateWindowSurface( gWindow );
    //     }
    // } 
    eventLoop();
    return 0;
}