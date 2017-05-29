#pragma once

#include <iostream>

namespace engine {
	namespace maths {

		struct vec3 {

			float x, y, z;

			vec3();
			vec3(const float& x, const float& y, const float& z);

			vec3& add(const vec3& that);
			vec3& subtract(const vec3& that);
			vec3& multiply(const vec3& that);
			vec3& divide(const vec3& that);

			friend vec3& operator+(vec3 left, const vec3& right);
			friend vec3& operator-(vec3 left, const vec3& right);
			friend vec3& operator*(vec3 left, const vec3& right);
			friend vec3& operator/(vec3 left, const vec3& right);

			bool operator==(const vec3& that);
			bool operator!=(const vec3& that);

			vec3& operator+=(const vec3& that);
			vec3& operator-=(const vec3& that);
			vec3& operator*=(const vec3& that);
			vec3& operator/=(const vec3& that);

			friend std::ostream& operator<<(std::ostream& stream, const vec3& vector);

		};

	}
}