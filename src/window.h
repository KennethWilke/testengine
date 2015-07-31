#ifndef __WINDOW_H__
#define __WINDOW_H__

#include <stdio.h>
#include "SDL2/SDL.h"
#include "SDL2/SDL_opengl.h"
#include "GL/glu.h"

SDL_GLContext opengl_context;
SDL_Window *window;

int create_window(char *title, int width, int height);
void free_window(void);

#endif
