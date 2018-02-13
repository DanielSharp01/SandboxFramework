#pragma once

#include <math.h>

namespace Sharp::Math
{
	struct Vector3;
	struct Vector4;
	struct Matrix4;

	struct Vector2
	{
		float x, y;
		Vector2(float x, float y);

		explicit Vector2(const Vector3& other);
		explicit Vector2(const Vector4& other);

		Vector2 operator+(const Vector2& other) const;
		Vector2& operator+=(const Vector2& other);

		Vector2 operator-(const Vector2& other) const;
		Vector2& operator-=(const Vector2& other);

		Vector2 operator*(const Vector2& other) const;
		Vector2& operator*=(const Vector2& other);
		Vector2 operator*(float other) const;
		Vector2& operator*=(float other);

		Vector2 operator/(const Vector2& other) const;
		Vector2& operator/=(const Vector2& other);
		Vector2 operator/(float other) const;
		Vector2& operator/=(float other);

		float dot(const Vector2& other);
		float perpDot(const Vector2& other);

		inline float getAngle() const
		{
			return atan2(y, x);
		}

		Vector2 transform(const Matrix4& other);
	};
}