#include <iostream>
#include <GLFW/glfw3.h>

#include "src\graphics\window.h"

int main() {

	using namespace engine;
	using namespace graphics;


	Window window(800, 600, "2D Engine");
	glClearColor(0.5f, 0.5f, 0.5f, 1.0f);

	while (!window.closed()) {
		window.clear();
		glBegin(GL_TRIANGLES);
		glVertex2f(-0.5f, -0.5f);
		glVertex2f( 0.0f, 0.5f);
		glVertex2f( 0.5f, -0.5f);
		glEnd();
		window.update();

		std::cout << window.getHeight() << "," << window.getWidth() << std::endl;

	}


	return 0;


}