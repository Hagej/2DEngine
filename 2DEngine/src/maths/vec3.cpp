#include "vec3.h"

namespace engine {
	namespace maths {

		vec3::vec3() {
			x = 0.0f;
			y = 0.0f;
			z = 0.0f;
		}

		vec3::vec3(const float& x, const float& y, const float& z) {
			this->x = x;
			this->y = y;
			this->z = z;
		}

		vec3& vec3::add(const vec3& that) {
			x += that.x;
			y += that.y;
			z += that.z;

			return *this;
		}

		vec3& vec3::subtract(const vec3& that) {
			x -= that.x;
			y -= that.y;
			z -= that.z;

			return *this;
		}

		vec3& vec3::multiply(const vec3& that) {
			x *= that.x;
			y *= that.y;
			z *= that.z;

			return *this;
		}

		vec3& vec3::divide(const vec3& that) {
			x /= that.x;
			y /= that.y;
			z /= that.z;

			return *this;
		}

		vec3 operator+(vec3 left, const vec3& right) {
			return left.add(right);
		}

		vec3 operator-(vec3 left, const vec3& right) {
			return left.subtract(right);
		}

		vec3 operator*(vec3 left, const vec3& right) {
			return left.multiply(right);
		}

		vec3 operator/(vec3 left, const vec3& right) {
			return left.divide(right);
		}


		bool vec3::operator==(const vec3& that) {
			return x == that.x && y == that.y && z == that.z;
		}

		bool vec3::operator!=(const vec3& that) {
			return !(*this == that);
		}


		vec3& vec3::operator+=(const vec3& that) {
			return add(that);
		}

		vec3& vec3::operator-=(const vec3& that) {
			return subtract(that);
		}

		vec3& vec3::operator*=(const vec3& that) {
			return multiply(that);
		}

		vec3& vec3::operator/=(const vec3& that) {
			return divide(that);
		}

		std::ostream& operator<<(std::ostream& stream, const vec3& vector) {
			stream << "vec3: (" << vector.x << ", " << vector.y << ", " << vector.z << ")";
			return stream;
		}

	}
}