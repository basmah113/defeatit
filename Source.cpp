#include "window.h"
#include "rect.h"

void pollEvents(Window& window, Rect& rect) {
    SDL_Event event;

    if (SDL_PollEvent(&event)) {
        rect.pollEvents(event);
        window.pollEvents(event);
    }
}

int main(int argc, char **argv) {

    Window window("DEFEAT IT", 800, 600);
    Rect rect(90, 90, 400, 500, "images/Happy Face Character.png");


    while (!window.isClosed()) {
        pollEvents(window, rect);
        rect.draw();
        window.clear();
    }

    return 0;
    
}


using namespace std;

#define SAFERELEASE(x) { if (x) { delete x; x = NULL;} }

SDL_Window* window = NULL;
SDL_Surface* renderFrame = NULL;


//[4] Create an array to store key states
//each key will be set to true if pressed


//[5] Create a sphere structure to handle collisions


//[6] Create a sprite structure which implements
//SDLs functionality of loading and drawing images
//along with collision detection


//[7] Create two instances of sprites



void LoadContent() {
	//[8] load in the two sprites. Set the
	// rect position and the square to not draw.

}

bool Update() {

	SDL_Event e;

	//[9] implement a loop to check all SDL events
	while (true) {

		//[10] Handle the X button at top right
		//of the window


		//[11] Detect keydown events

		//[12] Detect key up events


		//[13] detect mouse events


	}

	//[14] Move the rect when arrow keys are pressed


	//[15] Check for collision between rect and square


	return true;
}


