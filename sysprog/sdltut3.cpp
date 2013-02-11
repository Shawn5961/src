#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <string>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int SCREEN_BPP = 32;

SDL_Surface *image = NULL;
SDL_Surface * screen = NULL;

SDL_Event event;

SDL_Surface *load_image( std::string filename )
{
	SDL_Surface* loadedImage = NULL;

	SDL_Surface* optimizedImage = NULL;

	loadedImage = IMG_Load( filename.c_str() );

	if( loadedImage != NULL )
	{
		optimizedImage = SDL_DisplayFormat( loadedImage );

		SDL_FreeSurface( loadedImage );
	}

	return optimizedImage;
}

void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination )
{
	SDL_Rect offset;

	offset.x = x;
	offset.y = y;

	SDL_BlitSurface( source, NULL, destination, &offset );
}


