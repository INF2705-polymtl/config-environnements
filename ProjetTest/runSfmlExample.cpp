#include <cstddef>
#include <cstdint>

#include <iostream>
#include <string>
#include <cmath>

#include <glbinding/Binding.h>
#include <glbinding/gl/gl.h>
#include <SFML/Window.hpp>


using namespace gl;


void runSfmlExample(int& argc, char* argv[]) {
	sf::Window window;
	window.create(
		{600, 600},
		"Exemple SFML + glbinding",
		sf::Style::Default,
		sf::ContextSettings(24, 8)
	);
	window.setFramerateLimit(60);
	window.setActive(true);

	glbinding::Binding::initialize(nullptr, true);

	// Afficher les informations de base de la carte graphique et de la version OpenGL des drivers.
	auto openglVersion = glGetString(GL_VERSION);
	auto openglVendor = glGetString(GL_VENDOR);
	auto openglRenderer = glGetString(GL_RENDERER);
	auto glslVersion = glGetString(GL_SHADING_LANGUAGE_VERSION);
	auto& sfmlSettings = window.getSettings();
	printf("OpenGL        %s\n", openglVersion);
	printf("GPU           %s, %s\n", openglRenderer, openglVendor);
	printf("GLSL          %s\n", glslVersion);
	printf("SFML Context  %i.%i\n", sfmlSettings.majorVersion, sfmlSettings.minorVersion);
	printf("Depth bits    %i\n", sfmlSettings.depthBits);
	printf("Stencil bits  %i\n", sfmlSettings.stencilBits);

	float red = 0.0f;
	while (window.isOpen()) {
		glClearColor(red, 0, 0, 1);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		red += 0.01f;
		red = fmodf(red, 1.0f);

		window.display();
		sf::Event e;
		while(window.pollEvent(e)) {
			if (e.type == sf::Event::EventType::Closed)
				window.close();
		}
	}
}

