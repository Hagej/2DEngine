#include "vec4.h"

namespace engine {
	namespace maths {

		vec4::vec4() {
			x = 0.0f;
			y = 0.0f;
			z = 0.0f;
			w = 0.0f;
		}

		vec4::vec4(const float& x, const float& y, const float& z, const float& w) {
			this->x = x;
			this->y = y;
			this->z = z;
			this->w = w;
		}

		vec4& vec4::add(const vec4& that) {
			x += that.x;
			y += that.y;
			z += that.z;
			w += that.w;

			return *this;
		}

		vec4& vec4::subtract(const vec4& that) {
			x -= that.x;
			y -= that.y;
			z -= that.z;
			w -= that.w;

			return *this;
		}

		vec4& vec4::multiply(const vec4& that) {
			x *= that.x;
			y *= that.y;
			z *= that.z;
			w *= that.w;

			return *this;
		}

		vec4& vec4::divide(const vec4& that) {
			x /= that.x;
			y /= that.y;
			z /= that.z;
			w /= that.w;

			return *this;
		}

		vec4& operator+(vec4 left, const vec4& right) {
			return left.add(right);
		}

		vec4& operator-(vec4 left, const vec4& right) {
			return left.subtract(right);
		}

		vec4& operator*(vec4 left, const vec4& right) {
			return left.multiply(right);
		}

		vec4& operator/(vec4 left, const vec4& right) {
			return left.divide(right);
		}


		bool vec4::operator==(const vec4& that) {
			return x == that.x && y == that.y && z == that.z && w == that.w;
		}

		bool vec4::operator!=(const vec4& that) {
			return !(*this == that);
		}


		vec4& vec4::operator+=(const vec4& that) {
			return add(that);
		}

		vec4& vec4::operator-=(const vec4& that) {
			return subtract(that);
		}

		vec4& vec4::operator*=(const vec4& that) {
			return multiply(that);
		}

		vec4& vec4::operator/=(const vec4& that) {
			return divide(that);
		}

		std::ostream& operator<<(std::ostream& stream, const vec4& vector) {
			stream << "vec4: (" << vector.x << ", " << vector.y << ", " << vector.z << ", " << vector.w << ")";
			return stream;
		}

	}
}