#include <cstddef>
#include <cstdint>

#include <iostream>
#include <string>
#include <cmath>
#include <thread>
#include <chrono>

#include <SDL.h>
#include <GL/glew.h>


void runSdlExample(int& argc, char* argv[]) {
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
	SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);
	SDL_Window* window = SDL_CreateWindow(
		"Exemple SDL + GLEW",
		100, 100,
		600, 600,
		SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE
	);
	SDL_GL_CreateContext(window);
	SDL_GL_SetSwapInterval(1);
	glewExperimental = GL_TRUE;
	glewInit();
	
	float red = 0.0f;
	bool running = true;
	while (running) {
		glClearColor(red, 0, 0, 1);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		red += 0.01f;
		red = fmodf(red, 1.0f);

		SDL_GL_SwapWindow(window);
		SDL_Event e;
		while (SDL_PollEvent(&e)) {
			if (e.type == SDL_QUIT)
				running = false;
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(1000/60));
	}
}
