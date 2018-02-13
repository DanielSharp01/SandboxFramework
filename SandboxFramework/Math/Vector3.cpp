#include "Vector2.h"
#include "Vector3.h"
#include "Vector4.h"
#include "Matrix4.h"

namespace Sharp::Math
{
	Vector3::Vector3(float x, float y, float z)
		: x(x), y(y), z(z)
	{}

	Vector3::Vector3(const Vector2& other)
	{
		x = other.x;
		y = other.y;
		z = 0;
	}

	Vector3::Vector3(const Vector4& other)
	{
		x = other.x;
		y = other.y;
		z = other.z;
	}

	Vector3 Vector3::operator+(const Vector3& other) const
	{
		return Vector3(x + other.x, y + other.y, z + other.z);
	}

	Vector3& Vector3::operator+=(const Vector3& other)
	{
		x += other.x;
		y += other.y;
		z += other.y;
		return *this;
	}

	Vector3 Vector3::operator-(const Vector3& other) const
	{
		return Vector3(x - other.x, y - other.y, z - other.z);
	}

	Vector3& Vector3::operator-=(const Vector3& other)
	{
		x -= other.x;
		y -= other.y;
		z -= other.y;
		return *this;
	}

	Vector3 Vector3::operator*(const Vector3& other) const
	{
		return Vector3(x * other.x, y * other.y, z * other.z);
	}

	Vector3& Vector3::operator*=(const Vector3& other)
	{
		x *= other.x;
		y *= other.y;
		z *= other.z;
		return *this;
	}

	Vector3 Vector3::operator*(float other) const
	{
		return Vector3(x * other, y * other, z * other);
	}

	Vector3& Vector3::operator*=(float other)
	{
		x *= other;
		y *= other;
		z *= other;
		return *this;
	}

	Vector3 Vector3::operator/(const Vector3& other) const
	{
		return Vector3(x / other.x, y / other.y, z / other.z);
	}

	Vector3& Vector3::operator/=(const Vector3& other)
	{
		x /= other.x;
		y /= other.y;
		z /= other.z;
		return *this;
	}

	Vector3 Vector3::operator/(float other) const
	{
		return Vector3(x / other, y / other, z / other);
	}

	Vector3& Vector3::operator/=(float other)
	{
		x /= other;
		y /= other;
		z /= other;
		return *this;
	}

	float Vector3::dot(const Vector3& other)
	{
		return x * other.x + y * other.y + z * other.z;
	}

	Vector3 Vector3::cross(const Vector3& other)
	{
		return Vector3(y * other.z - y * other.y, x * other.z - z * other.x, x * other.y - y * other.x);
	}

	Vector3 Vector3::transform(const Matrix4& other)
	{
		return (Vector3)(other * (Vector4)(*this));
	}
}