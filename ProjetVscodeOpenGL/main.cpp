#include <cstddef>
#include <cstdint>

#include <iostream>
#include <string>
#include <cmath>


void runGlutExample(int& argc, char* argv[]); // GLUT
void runSfmlExample(int& argc, char* argv[]); // SFML + glbinding
void runSdlExample(int& argc, char* argv[]);  // SDL + GLEW


int main(int argc, char* argv[]) {
	std::cout << "Hello, world!" << "\n\n";

	// Décommentez une fonction pour tester cette configuration.
	//runSfmlExample(argc, argv);
	//runGlutExample(argc, argv);
	//runSdlExample(argc, argv);
}

