#include <iostream>

#include "src\graphics\window.h"
#include "src\maths\maths.h"
#include "src\utils\fileutils.h"
#include "src\graphics\shader.h"

#include "src\graphics\buffers\buffer.h"
#include "src\graphics\buffers\indexbuffer.h"
#include "src\graphics\buffers\vertexarray.h"

#include "src\graphics\simple2drenderer.h"
#include "src\graphics\renderable2d.h"

#define WINDOW_WIDTH	960
#define WINDOW_HEIGHT	540

int main() {


	using namespace engine;
	using namespace graphics;
	using namespace maths;

	Window window(WINDOW_WIDTH, WINDOW_HEIGHT, "2D Engine");
	glClearColor(0.0, 0.0f, 0.0f, 1.0f);

	mat4 ortho = mat4::orthographic(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f);

	Shader shader("src/shaders/basic.vert", "src/shaders/basic.frag");
	shader.enable();
	shader.setUniformMat4("pr_matrix", ortho);
	shader.setUniformMat4("ml_matrix", mat4::translation(vec3(4, 3, 0)));

	Renderable2D sprite(maths::vec3(5, 5, 0), maths::vec2(4, 4), maths::vec4(1, 0, 1, 1), shader);
	Renderable2D sprite2(maths::vec3(1, 1, 0), maths::vec2(3, 5), maths::vec4(0, 0, 1, 1), shader);
	Simple2DRenderer renderer;

	shader.setUniform2f("light_pos", vec2(4.0f, 1.5f));
	shader.setUniform4f("col", vec4(0.2f, 0.3f, 0.8f, 1.0f));

	
	while (!window.closed()) {
		window.clear();
		double x, y;
		window.getMousePosition(x, y);
		shader.setUniform2f("light_pos", vec2((float)(x * 16.0f / WINDOW_WIDTH), (float)(9.0f - y * 9.0f / WINDOW_HEIGHT)));

		renderer.submit(&sprite);
		renderer.submit(&sprite2);
		renderer.flush();


		window.update();

	}


	return 0;


}