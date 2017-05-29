#include <iostream>

#include "src\graphics\window.h"
#include "src\maths\vec2.h"

int main() {

	using namespace engine;
	using namespace graphics;
	using namespace maths;

	Window window(800, 600, "2D Engine");
	glClearColor(0.5f, 0.5f, 0.5f, 1.0f);

	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	vec2 a(1, 2);
	vec2 b(3, 4);

	vec2 c = a + b;

	std::cout << "a = " << a << "  b = " << b << "  c = " << c << std::endl;

	while (!window.closed()) {
		window.clear();

		

		glBegin(GL_TRIANGLES);
		glVertex2f(-0.5f, -0.5f);
		glVertex2f( 0.0f, 0.5f);
		glVertex2f( 0.5f, -0.5f);
		glEnd();
		window.update();

	}


	return 0;


}