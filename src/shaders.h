#ifndef __SHADERS_H__
#define __SHADERS_H__

#include "testengine.h"


typedef struct
{
	GLuint vertex;
	GLuint fragment;
	GLuint program;
} shader;

shader* load_shader(const char *vertex_file, const char *fragment_file);

#endif
