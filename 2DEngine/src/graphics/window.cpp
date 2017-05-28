#include "window.h"


namespace engine {
	namespace graphics {

		void window_size_callback(GLFWwindow *window, int width, int height);

		Window::Window(int width, int height, const char *title) {
			m_Title = title;
			m_Width = width;
			m_Height = height;
			if (!init()) {
				glfwTerminate();
			}

		}

		Window::~Window() {
			glfwDestroyWindow(m_Window);
			glfwTerminate();
		}

		bool Window::init() {

			if (!glfwInit()) {			// Initialize GLFW
				std::cout << "Failed to initialize GLFW!" << std::endl;
				return false;
			}

			m_Window = glfwCreateWindow(m_Width, m_Height, m_Title, NULL, NULL); // Width and height in pixels, title of window, monitor to use for fullscreen (windowed mode if NULL), window whose context to share resources with, NULL to not share resources.

			if (!m_Window) {			// Initialize GLFW window
				std::cout << "Failed to create GLFW window!" << std::endl;
				return false;
			}

			glfwSetWindowSizeCallback(m_Window, window_size_callback);
			glfwMakeContextCurrent(m_Window);

			if (glewInit() != GLEW_OK) {
				std::cout << "Failed to initialize GLEW!" << std::endl;
			}

			return true;
		}

		void Window::clear() const {	// Clear window color and depth buffer
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		}


		void Window::update() {

			glfwPollEvents();
			glfwSwapBuffers(m_Window);

		}

		bool Window::closed() const {
			return glfwWindowShouldClose(m_Window) == 1;
		}

		void window_size_callback(GLFWwindow *window, int width, int height) {
			glViewport(0, 0, width, height);
		}
	}
}


