#ifndef __WINDOW_H__
#define __WINDOW_H__

#include <stdio.h>
#include "SDL2/SDL.h"
#include "SDL2/SDL_opengl.h"
#include "GL/glu.h"

SDL_Renderer *renderer;

int create_window(void);
void free_window(void);

#endif
