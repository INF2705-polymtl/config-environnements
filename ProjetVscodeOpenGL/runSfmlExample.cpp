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

