#pragma once

#include <iostream>
#include <glew.h>
#include <GLFW\glfw3.h>


namespace engine {
	namespace graphics {

#define MAX_KEYS	1024
#define MAX_BUTTONS	32

		class Window {

		private:
			const char *m_Title;
			int m_Width, m_Height;
			GLFWwindow *m_Window;

			bool m_Keys[MAX_KEYS];
			bool m_MouseButtons[MAX_BUTTONS];
			double mx, my;

		public:
			Window(int width, int height, const char* title);
			~Window();
			void clear() const;
			void update();
			bool closed() const;

			bool isKeyPressed(unsigned int keycode);
			bool isMouseButtonPressed(unsigned int button);
			void getMousePosition(double& x, double& y);

			inline int getWidth() const { return m_Width; };
			inline int getHeight() const { return m_Height; };

		private: 
			bool init();

			friend static void window_size_callback(GLFWwindow *window, int width, int height);
			friend static void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods);
			friend static void cursor_callback(GLFWwindow *window, double xpos, double ypos);
			friend static void mouse_button_callback(GLFWwindow *window, int button, int action, int mods);
			

		};


	}
}