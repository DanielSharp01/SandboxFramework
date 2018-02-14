#include "Vector2.h"
#include "Vector3.h"
#include "Vector4.h"
#include "Matrix4.h"

namespace Sandbox::Math
{
	Vector4::Vector4(float x, float y, float z, float w)
		: x(x), y(y), z(z), w(w)
	{}

	Vector4::Vector4(const Vector2& other)
	{
		x = other.x;
		y = other.y;
		z = 0;
		w = 1;
	}

	Vector4::Vector4(const Vector3& other)
	{
		x = other.x;
		y = other.y;
		z = other.z;
		w = 1;
	}

	Vector4 Vector4::operator+(const Vector4& other) const
	{
		return Vector4(x + other.x, y + other.y, z + other.z, w + other.w);
	}

	Vector4& Vector4::operator+=(const Vector4& other)
	{
		x += other.x;
		y += other.y;
		z += other.y;
		w += other.w;
		return *this;
	}

	Vector4 Vector4::operator-() const
	{
		return Vector2(-x, -y, -z, -w);
	}

	Vector4 Vector4::operator-(const Vector4& other) const
	{
		return Vector4(x - other.x, y - other.y, z - other.z, w - other.w);
	}

	Vector4& Vector4::operator-=(const Vector4& other)
	{
		x -= other.x;
		y -= other.y;
		z -= other.y;
		w -= other.w;
		return *this;
	}

	Vector4 Vector4::operator*(const Vector4& other) const
	{
		return Vector4(x * other.x, y * other.y, z * other.z, w * other.w);
	}

	Vector4& Vector4::operator*=(const Vector4& other)
	{
		x *= other.x;
		y *= other.y;
		z *= other.z;
		w *= other.w;
		return *this;
	}

	Vector4 Vector4::operator*(float other) const
	{
		return Vector4(x * other, y * other, z * other, w * other);
	}

	Vector4& Vector4::operator*=(float other)
	{
		x *= other;
		y *= other;
		z *= other;
		w *= other;
		return *this;
	}

	Vector4 Vector4::operator/(const Vector4& other) const
	{
		return Vector4(x / other.x, y / other.y, z / other.z, w / other.w);
	}

	Vector4& Vector4::operator/=(const Vector4& other)
	{
		x /= other.x;
		y /= other.y;
		z /= other.z;
		w /= other.w;
		return *this;
	}

	Vector4 Vector4::operator/(float other) const
	{
		return Vector4(x / other, y / other, z / other, w / other);
	}

	Vector4& Vector4::operator/=(float other)
	{
		x /= other;
		y /= other;
		z /= other;
		w /= other;
		return *this;
	}

	float Vector4::Dot(const Vector4& other) const
	{
		return x * other.x + y * other.y + z * other.z + w * other.w;
	}

	Vector4 Vector4::Normalize() const
	{
		return *this / Length();
	}

	Vector4 Vector4::Transform(const Matrix4& other) const
	{
		return other * (*this);
	}
}