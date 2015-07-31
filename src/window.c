#include "window.h"


void free_window(void)
{
	SDL_GL_DeleteContext(opengl_context);
	SDL_DestroyWindow(window);
}


void set_viewport(int width, int height)
{
}


int create_window(char *title, int width, int height)
{
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK,
	                    SDL_GL_CONTEXT_PROFILE_CORE);

	window = SDL_CreateWindow(title, 0, 0, width, height, SDL_WINDOW_OPENGL);
	opengl_context = SDL_GL_CreateContext(window);

	set_viewport(width, height);

	return 0;
}
