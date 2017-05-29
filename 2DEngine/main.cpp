#include <iostream>

#include "src\graphics\window.h"

int main() {

	using namespace engine;
	using namespace graphics;

	Window window(800, 600, "2D Engine");
	glClearColor(0.5f, 0.5f, 0.5f, 1.0f);

	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	while (!window.closed()) {
		window.clear();

		if (window.isKeyPressed(GLFW_KEY_A)) {
			std::cout << "A PRESSED!" << std::endl;
		}

		if (window.isMouseButtonPressed(GLFW_MOUSE_BUTTON_LEFT)) {
			std::cout << "LEFT PRESSED!" << std::endl;
		}

		glBegin(GL_TRIANGLES);
		glVertex2f(-0.5f, -0.5f);
		glVertex2f( 0.0f, 0.5f);
		glVertex2f( 0.5f, -0.5f);
		glEnd();
		window.update();

	}


	return 0;


}