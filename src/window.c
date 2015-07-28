#include "window.h"

SDL_Window *window;
SDL_RendererInfo renderer_info;


void free_window(void)
{
	SDL_DestroyWindow(window);
}


void init_opengl()
{
}


void set_viewport(int width, int height)
{
   glViewport(0, 0, (GLsizei) width, (GLsizei) height);
   glLoadIdentity();
   glFrustum(-1.0, 1.0, -1.0, 1.0, 1.5, 20.0);
   glMatrixMode(GL_MODELVIEW);
}


int create_window(void)
{
	if(SDL_CreateWindowAndRenderer(800, 600, SDL_WINDOW_OPENGL, &window,
	                               &renderer))
	{
		fprintf(stderr, "Failed to initialize window: %s\n", SDL_GetError());
	}

	SDL_GetRendererInfo(renderer, &renderer_info);
	
	printf("Renderer: %s\n", renderer_info.name);

	init_opengl();
	set_viewport(800, 600);

	return 0;
}
