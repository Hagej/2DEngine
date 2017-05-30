#pragma once

#include <iostream>

namespace engine {
	namespace maths {

		struct vec2 {

			float x, y;

			vec2();
			vec2(const float& x, const float& y);

			vec2& add(const vec2& that);
			vec2& subtract(const vec2& that);
			vec2& multiply(const vec2& that);
			vec2& divide(const vec2& that);

			friend vec2 operator+(vec2 left, const vec2& right);
			friend vec2 operator-(vec2 left, const vec2& right);
			friend vec2 operator*(vec2 left, const vec2& right);
			friend vec2 operator/(vec2 left, const vec2& right);

			bool operator==(const vec2& that);
			bool operator!=(const vec2& that);

			vec2& operator+=(const vec2& that);
			vec2& operator-=(const vec2& that);
			vec2& operator*=(const vec2& that);
			vec2& operator/=(const vec2& that);

			friend std::ostream& operator<<(std::ostream& stream, const vec2& vector);

		};

	}
}