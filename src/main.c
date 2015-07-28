#include "main.h"

int start_subsystems(void);
void stop_subsystems(void);


int main(int argc, char *argv[])
{
	int running = 1;

	if(start_subsystems())
	{
		return 1;
	}

	while(running)
	{
		running = process_event();
		draw_frame();
	}

	stop_subsystems();
	return 0;
}


int start_subsystems(void)
{
	SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO);

	if(create_window())
		return 1;

	return 0;
}


void stop_subsystems(void)
{
	free_window();
	SDL_Quit();
}
