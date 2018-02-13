#include "Vector2.h"
#include "Vector3.h"
#include "Vector4.h"
#include "Matrix4.h"

namespace Sandbox::Math
{
	Vector2::Vector2(float x, float y)
		: x(x), y(y)
	{}

	Vector2::Vector2(const Vector3& other)
	{
		x = other.x;
		y = other.y;
	}

	Vector2::Vector2(const Vector4& other)
	{
		x = other.x;
		y = other.y;
	}

	Vector2 Vector2::operator+(const Vector2& other) const
	{
		return Vector2(x + other.x, y + other.y);
	}

	Vector2& Vector2::operator+=(const Vector2& other)
	{
		x += other.x;
		y += other.y;
		return *this;
	}

	Vector2 Vector2::operator-(const Vector2& other) const
	{
		return Vector2(x - other.x, y - other.y);
	}

	Vector2& Vector2::operator-=(const Vector2& other)
	{
		x -= other.x;
		y -= other.y;
		return *this;
	}

	Vector2 Vector2::operator*(const Vector2& other) const
	{
		return Vector2(x * other.x, y * other.y);
	}

	Vector2& Vector2::operator*=(const Vector2& other)
	{
		x *= other.x;
		y *= other.y;
		return *this;
	}

	Vector2 Vector2::operator*(float other) const
	{
		return Vector2(x * other, y * other);
	}

	Vector2& Vector2::operator*=(float other)
	{
		x *= other;
		y *= other;
		return *this;
	}

	Vector2 Vector2::operator/(const Vector2& other) const
	{
		return Vector2(x / other.x, y / other.y);
	}

	Vector2& Vector2::operator/=(const Vector2& other)
	{
		x /= other.x;
		y /= other.y;
		return *this;
	}

	Vector2 Vector2::operator/(float other) const
	{
		return Vector2(x / other, y / other);
	}

	Vector2& Vector2::operator/=(float other)
	{
		x /= other;
		y /= other;
		return *this;
	}

	float Vector2::Dot(const Vector2& other) const
	{
		return x * other.x + y * other.y;
	}

	float Vector2::PerpDot(const Vector2& other) const
	{
		return x * other.y - y * other.x;
	}

	Vector2 Vector2::Transform(const Matrix4& other) const
	{
		return (Vector2)(other * (Vector4)(*this));
	}
}