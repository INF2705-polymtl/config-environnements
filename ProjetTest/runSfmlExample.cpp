#include <cstddef>
#include <cstdint>

#include <iostream>
#include <string>
#include <cmath>

#include <glbinding/Binding.h>
#include <glbinding/gl/gl.h>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


using namespace gl;


void runSfmlExample(int& argc, char* argv[]) {
	// Créer la fenêtre et initialiser le contexte OpenGL.
	sf::RenderWindow window;
	window.create(
		sf::VideoMode({600, 600}),  // Dimensions de la fenêtre
		"Exemple SFML + glbinding", // Titre
		sf::Style::Default,         // Style de fenêtre (avec barre de titre et boutons).
		sf::State::Windowed,        // État de la fenêtre au démarrage.
		sf::ContextSettings{24}     // Taille du tampon de profondeur. 24 bit est pas mal le standard.
	);
	window.setFramerateLimit(30); // Le FPS d'affichage.
	bool ok = window.setActive(true);
	if (not ok)
		std::cout << "Oups!" << std::endl;
	glbinding::Binding::initialize(nullptr, true); // La résolution des fonctions d'OpenGL.

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
		glClear(GL_COLOR_BUFFER_BIT);

		red += 0.01f;
		red = fmodf(red, 1.0f);

		window.display();

		// On pourrait gérer les évènements de fenêtre (clavier, redimensionnement, fermeture, etc), mais pour aujourd'hui on va juste traiter l'événement de fermeture de fenêtre.
		while (auto e = window.pollEvent()) {
			// On arrête si l'utilisateur appuie sur le X de la fenêtre (ou le raccourci clavier associé tel que Alt+F4 sur Windows).
			if (e->is<sf::Event::Closed>())
				window.close();
		}
	}
}

