#include "window.h"


namespace engine {
	namespace graphics {

		bool Window::m_Keys[MAX_KEYS];
		bool Window::m_MouseButtons[MAX_BUTTONS];
		double Window::mx, Window::my;

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

		bool Window::init() {																	// Initialize window

			if (!glfwInit()) {																	// Initialize GLFW
				std::cout << "Failed to initialize GLFW!" << std::endl;
				return false;
			}

			m_Window = glfwCreateWindow(m_Width, m_Height, m_Title, NULL, NULL);				/* Width and height in pixels, title of window, monitor to use for fullscreen (windowed mode if NULL)
																								 window whose context to share resources with, NULL to not share resources.*/

			if (!m_Window) {																	// Initialize GLFW window
				std::cout << "Failed to create GLFW window!" << std::endl;
				return false;
			}

			glfwSetWindowUserPointer(m_Window, this);
			glfwSetWindowSizeCallback(m_Window, window_size_callback);
			glfwSetKeyCallback(m_Window, key_callback);
			glfwSetCursorPosCallback(m_Window, cursor_callback);
			glfwSetMouseButtonCallback(m_Window, mouse_button_callback);
			glfwMakeContextCurrent(m_Window);

			if (glewInit() != GLEW_OK) {														// Initialize GLEW
				std::cout << "Failed to initialize GLEW!" << std::endl;
			}

			std::cout << "OpenGL version: " << glGetString(GL_VERSION) << std::endl;


			return true;
		}   

		void Window::clear() const {															// Clear window color and depth buffer
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		}


		void Window::update() {

			glfwPollEvents();
			glfwSwapBuffers(m_Window);

		}

		bool Window::closed() const {
			return glfwWindowShouldClose(m_Window) == 1;
		}

		bool Window::isKeyPressed(unsigned int keycode) {
			// TODO: Log this
			if (keycode >= MAX_KEYS) { return false; }
			return m_Keys[keycode];
		}

		bool Window::isMouseButtonPressed(unsigned int button) {
			if (button >= MAX_BUTTONS) { return false; }
			return m_MouseButtons[button];
		}

		void Window::getMousePosition(double& x, double& y) {
			x = mx;
			y = my;
		}


		/***	CALLBACKS	 ***/

		void window_size_callback(GLFWwindow *window, int width, int height) {					// Callback for changing window size
			Window* win = (Window*)glfwGetWindowUserPointer(window);
			win->m_Width = width;
			win->m_Height = height;
			glViewport(0, 0, width, height);
		}

		void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods) {	// Callback for input handling
			Window* win = (Window*) glfwGetWindowUserPointer(window);
			win->m_Keys[key] = (action != GLFW_RELEASE);										// Set key to true if not released
	
		}

		void cursor_callback(GLFWwindow *window, double xpos, double ypos) {					// Callback for cursor movement
			Window* win = (Window*)glfwGetWindowUserPointer(window);
			win->mx = xpos;
			win->my = ypos;
		}

		void mouse_button_callback(GLFWwindow *window, int button, int action, int mods) {
			Window* win = (Window*)glfwGetWindowUserPointer(window);
			win->m_MouseButtons[button] = (action != GLFW_RELEASE);								// Set button to true if not released
		}


	}
}


