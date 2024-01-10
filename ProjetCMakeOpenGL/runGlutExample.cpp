//
// Ce fichier


#include <cstddef>
#include <cstdint>

#include <iostream>
#include <string>
#include <cmath>
#include <thread>
#include <chrono>

#include <GL/glut.h>


void draw() {
	static float red = 0.0f;

	glClearColor(red, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	red += 0.01f;
	red = fmodf(red, 1.0f);

	glutSwapBuffers();
	std::this_thread::sleep_for(std::chrono::milliseconds(1000/60));
}


void runGlutExample(int& argc, char* argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(600, 600);
	glutCreateWindow("Exemple GLUT");
	glutDisplayFunc(draw);
	glutIdleFunc(draw);
	glutMainLoop();
}

