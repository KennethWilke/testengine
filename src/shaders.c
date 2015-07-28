#include "shaders.h"

void test(void)
{
	GLuint shader_id;
	
	shader_id = glCreateShader(GL_VERTEX_SHADER);
	printf("shader: %u\n", shader_id);
}
