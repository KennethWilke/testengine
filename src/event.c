#include "event.h"

int window_event(SDL_Event *event)
{
	switch(event->window.event)
	{
		case SDL_WINDOWEVENT_CLOSE:
			return 0;
			break;
	}
	return 1;
}


int process_event(void)
{
	SDL_Event event;

	// Poll for an event or return if none available
	if(!SDL_PollEvent(&event))
		return 1;

	if(event.type == SDL_WINDOWEVENT)
	{
		return window_event(&event);
	}
	return 1;
}
