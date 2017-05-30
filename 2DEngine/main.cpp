#include <iostream>

#include "src\graphics\window.h"
#include "src\maths\maths.h"

int main() {

	using namespace engine;
	using namespace graphics;
	using namespace maths;

	Window window(800, 600, "2D Engine");
	glClearColor(0.5f, 0.5f, 0.5f, 1.0f);

	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	mat4 trans = mat4::translation(vec3(3, 4, 5));

	vec4 c0 = trans.columns[0];
	vec4 c1 = trans.columns[1];
	vec4 c2 = trans.columns[2];
	vec4 c3 = trans.columns[3];

	std::cout << c0 << std::endl;
	std::cout << c1 << std::endl;
	std::cout << c2 << std::endl;
	std::cout << c3 << std::endl;

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