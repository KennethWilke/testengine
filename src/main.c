#include "main.h"

int start_subsystems(void);
void stop_subsystems(void);

static const GLfloat triangle[] =
{
	-0.8f, -0.8f, 0.0f,
	0.8f, -0.8, 0.0f,
	0.0f, 0.8f, 0.0f
};


int main(int argc, char *argv[])
{
	int running = 1;
	shader *testshader;

	if(start_subsystems())
	{
		return 1;
	}

	testshader = load_shader("vertex.glsl", "fragment.glsl");
	if(!testshader)
	{
		fprintf(stderr, "Cannot render without valid shader program\n");
		stop_subsystems();
		return 1;
	}

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

	GLuint vertexarray;
	glGenVertexArrays(1, &vertexarray);
	glBindVertexArray(vertexarray);

	GLuint vertexbuffer;
	glGenBuffers(1, &vertexbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(triangle), triangle, GL_STATIC_DRAW);

	while(running)
	{
		running = process_event();

		glClear(GL_COLOR_BUFFER_BIT);

		glUseProgram(testshader->program);

		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);

		glDrawArrays(GL_TRIANGLES, 0, 3);

		glDisableVertexAttribArray(0);

		SDL_GL_SwapWindow(window);
		
	}

	stop_subsystems();
	return 0;
}


int start_subsystems(void)
{
	SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO);

	if(create_window("test", 800, 600))
		return 1;

	return 0;
}


void stop_subsystems(void)
{
	free_window();
	SDL_Quit();
}
