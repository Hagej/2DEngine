#pragma once

#include <iostream>
#include <glew.h>
#include <GLFW\glfw3.h>


namespace engine {
	namespace graphics {


		class Window {

		private:
			const char *m_Title;
			int m_Width, m_Height;
			GLFWwindow *m_Window;

		public:
			Window(int width, int height, const char* title);
			~Window();
			void clear() const;
			void update();
			bool closed() const;

			inline int getWidth() const { return m_Width; };
			inline int getHeight() const { return m_Height; };

		private: 
			bool init();
			

		};


	}
}