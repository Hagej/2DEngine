#pragma once

#include <glew.h>

namespace engine {
	namespace graphics {

		class IndexBuffer {

		private:
			GLuint m_BufferID;
			GLuint m_Count;
		public:

			IndexBuffer(GLushort* data, GLsizei count);

			void bind() const;
			void unbind() const;

			inline GLuint getCount() { return m_Count; }

		};

	}
}